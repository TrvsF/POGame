#include "player.h"

player::player(Vector2 position)
{
	pos(position);

	m_inputs = inputs::INSTANCE();

	setTexture("player.png");
	m_xHairTex = new texture("xhair.png");
	m_xHairTexRed = new texture("xhair_red.png");

	type(EntityType::PLAYER);

	m_currentWeapon = NULL;

	m_camera = new camera();
	m_camera->bb(centerPos().x, centerPos().y, 400, 400);

	m_tickVelocity = 0;
	m_pickupDelayTimer = 0;
	m_boostIndex = 0;
	m_boostCooldownCount = 0;

	m_canBoost = true;
	m_hasBoosted = false;

	physics::INSTANCE()->addEntity(this);
}

player::~player()
{
}

void player::playerInput()
{
	if (m_inputs->keyDown(SDL_SCANCODE_W))
	{
		moveForward();
	}
	if (m_inputs->keyDown(SDL_SCANCODE_S))
	{
		moveBackward();
	}
	if (m_inputs->keyDown(SDL_SCANCODE_D))
	{
		turnRight();
	}
	if (m_inputs->keyDown(SDL_SCANCODE_A))
	{
		turnLeft();
	}
	if (m_inputs->keyPressed(SDL_SCANCODE_SPACE))
	{
		boost();
	}
	if (m_inputs->mouseButtonPressed(inputs::left))
	{
		shoot();
	}
}

void player::checkBoostCooldown()
{
	if (!m_canBoost)
	{
		m_boostCooldownCount++;
		if (m_boostCooldownCount > BOOST_COOLDOWN)
		{
			m_canBoost = true;
			m_boostCooldownCount = 0;
		}
	}
}

// calculate new player velocity given some ammount to add
float player::calcVelocity()
{
	// get what the velocity would be
	float vel = velocity() + m_tickVelocity;
	float velMag = abs(vel);

	// if is going too fast even for boost clamp vel
	if (velMag > MAX_VEL_BOOST)
	{
		vel = vel > 0 ? MAX_VEL_BOOST : -MAX_VEL_BOOST;
	}

	// if no velocity is being added then either remain at rest
	// or start to slow the character down
	if (m_tickVelocity == 0)
	{
		// if vel is close to 0 set to 0
		if (velMag < 0.05f)
		{
			return 0;
		}
		// else return the player's velocity but slowed down
		return vel > 0 ? vel - 0.05f : vel + 0.05f;
	}

	// if calculated velocity is over the max then return max veloicty (- or +)
	if (velMag > MAX_VEL && !m_hasBoosted)
	{
		return vel > 0 ? MAX_VEL : -MAX_VEL;
	}

	// else return the newly calculated velocity
	return vel;
}

void player::turnRight()
{
	m_boostIndex++;
	rotation(rotation() + 3.5f);
}

void player::turnLeft()
{
	m_boostIndex++;
	rotation(rotation() - 3.5f);
}

void player::moveForward()
{
	if (velocity() >= -MAX_VEL)
		m_tickVelocity -= 0.2f;
}

void player::moveBackward()
{
	if (velocity() <= MAX_VEL)
		m_tickVelocity += 0.2f;
}

void player::boost()
{
	// if can boost, booost
	if (m_canBoost)
	{
		velocity(velocity() * BOOST_MUL[m_boostIndex]);
		m_hasBoosted = true;
	}

	// if player is moving while boosting cancel the boost
	// [mimick bhoping]
	if (m_inputs->keyDown(SDL_SCANCODE_W) || m_inputs->keyDown(SDL_SCANCODE_S))
		m_canBoost = false;
}

bool player::shouldMoveObjects(Vector2 movementVec)
{
	BoundingBox checkBB = m_camera->bb() + movementVec;
	if (checkBB.isOutOfBounds(1920, 1080))
	{
		return true;
	}
	return false;
}

void player::movePlayer(Vector2 movementVec)
{
	if (shouldMoveObjects(movementVec))
	{
		physics::INSTANCE()->translateEntitiesNotPlayer(-movementVec);
	}
	else
	{
		translate(movementVec);
		m_camera->translate(movementVec);
	}
}

void player::shoot()
{
	if (!canShoot())
		return;

	float ang = getAngleFromVecsNormal(Vector2(centerPos().x, centerPos().y), m_inputs->mousePos());

	m_currentWeapon->shoot(ang);
}

void player::renderXhair()
{
	if (canShoot())
	{
		m_xHairTex->render(Vector2(m_inputs->mousePos().x, m_inputs->mousePos().y), 0);
	}
	else
	{
		m_xHairTexRed->render(Vector2(m_inputs->mousePos().x, m_inputs->mousePos().y), 0);
	}
}

bool player::canShoot()
{
	if (m_currentWeapon == NULL)
		return false;

	float angDiff = rotation() - getAngleFromVecsNormal(centerPos(), m_inputs->mousePos());
	float magDiff = abs(angDiff);

	if (magDiff < 70.0f || magDiff > 290.0f)
		return true;

	return false;
}

void player::checkPickup()
{
	if (m_pickupDelayTimer < PICKUP_DELAY)
		return;

	m_pickupDelayTimer = 0;
	pickup* pickup = physics::INSTANCE()->getPickupsWithBB(bb());

	if (pickup == NULL)
		return;

	if (m_currentWeapon != NULL)
		m_currentWeapon->onDrop();

	pickup->onPickup(this);
	m_currentWeapon = pickup;
}

void player::updatePickup()
{
	if (m_currentWeapon == NULL)
		return;

	m_currentWeapon->pos(Vector2( pos().x + 4, pos().y));
	m_currentWeapon->rotation(rotation());
}

Vector2 player::getMovement()
{
	float calcVel = calcVelocity();
	velocity(calcVel);
	Vector2 movement = Vector2(0, calcVel);
	return RotateVector(movement, rotation());
}

void player::cancelBoost()
{
	if (abs(velocity()) > MAX_VEL)
		m_canBoost = false;
}

void player::handleQuarterSteps()
{
	Vector2 movementVec = getMovement();

	movementVec = movementVec / 4.0f;

	for (int i = 0; i < 4; i++)
	{
		BoundingBox nextFrameBB = bb() + movementVec;

		// if player is going to collide with another object
		if (physics::INSTANCE()->isAnythingNotSelfGoingToCollideWithBB(nextFrameBB, this))
		{
			// cancel the player's boost
			cancelBoost();

			// try and move only 1 axis (for the sliding against the wall effect
			Vector2 xVec = Vector2(movementVec.x, 0);
			Vector2 yVec = Vector2(0, movementVec.y);

			BoundingBox xbb = bb() + xVec;
			BoundingBox ybb = bb() + yVec;

			// can move x
			if (!physics::INSTANCE()->isAnythingNotSelfGoingToCollideWithBB(xbb, this))
			{
				movePlayer(xVec);
			}
			// can move y
			if (!physics::INSTANCE()->isAnythingNotSelfGoingToCollideWithBB(ybb, this))
			{
				movePlayer(yVec);
			}
		}
		// if not
		else
		{
			movePlayer(movementVec);
		}
	}
}

void player::update()
{
	// check the player's input
	playerInput();

	// check if cooldown is over
	checkBoostCooldown();

	// handle player movement
	handleQuarterSteps();

	// check if player can pickup
	checkPickup();
	updatePickup();
	
	/*
	printf("vel : %f | pos %.1f, %.1f | rot %.1f | mouse rot %.1f | rotdiff %.1f | boost : %d\n",
		velocity(),
		pos().x,
		pos().y,
		rotation(),
		getAngleFromVecsNormal(centerPos(), m_inputs->mousePos()),
		abs(rotation() - getAngleFromVecsNormal(centerPos(), m_inputs->mousePos())),
		m_canBoost)
	*/
	

	// reset tick based vars
	m_boostIndex = 0;
	m_tickVelocity = 0;
	m_hasBoosted = false;

	m_pickupDelayTimer++;
}

void player::render()
{
	// drawDebugBB();
	m_camera->render();
	renderTexture();
	renderXhair();
}