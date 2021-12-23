#include "player_object.h"

player_object::player_object(const char* texturesheet, int x, int y)
{
	m_playerTexture = texture_helper::loadTexture(texturesheet);

	m_srcRect.h = 32;
	m_srcRect.w = 32;
	m_srcRect.x = 0;
	m_srcRect.y = 0;

	m_posX = 400;
	m_posY = 300;

	/*
		0 = forward
		1 = backward
		2 = left
		3 = right

		DONT DO THIS AS A FOR LOOP IT BREAKS EVERYTHING!!!
	*/
	movementVector[0] = 0;
	movementVector[1] = 0;
	movementVector[2] = 0;
	movementVector[3] = 0;

	m_angle = 0;
	m_velocity = 0;
}

player_object::~player_object()
{

}

void player_object::update()
{
	printf("angle : %f, moveVel : %f, coords : %f,%f\n", m_angle, m_velocity, m_posX, m_posY);

	handleMovement();
	handleTurning();

	moveToPoint();

}

void player_object::render()
{
	m_destRect.x = m_posX;
	m_destRect.y = m_posY;
	SDL_QueryTexture(m_playerTexture, NULL, NULL, &m_destRect.w, &m_destRect.h);
	m_destRect.x -= (m_destRect.w / 2);
	m_destRect.y -= (m_destRect.h / 2);

	double textureAngle = (m_angle + M_PI / 2.0f) * 180.0f / M_PI;

	SDL_RenderCopyEx(m_renderer, m_playerTexture, NULL, &m_destRect, textureAngle, NULL, SDL_FLIP_NONE);
}

void player_object::handleTurning()
{
	// if moving forward key is down 
	if (movementVector[2] == 1)
	{
		m_angle -= TURNING_MOMENTUM;
	}

	// if moving backward key is down
	if (movementVector[3] == 1)
	{
		m_angle += TURNING_MOMENTUM;
	}
}

void player_object::handleMovement()
{
	// if moving forward key is down 
	if (movementVector[0] == 1)
	{
		if (m_velocity >= MAX_VEL)
		{
			m_velocity = MAX_VEL;
		}
		else
		{
			m_velocity += MOVEMENT_MOMENTUM;
		}
	}

	// if moving backward key is down
	if (movementVector[1] == 1)
	{
		if (m_velocity <= -MAX_VEL)
		{
			m_velocity = -MAX_VEL;
		}
		else
		{
			m_velocity -= MOVEMENT_MOMENTUM;
		}
	}

	// if no movement keys are pressed
	if (movementVector[0] == 0 && movementVector[1] == 0)
	{
		m_velocity = 0;
	}
}

void player_object::moveToPoint()
{
	float x = std::cosf(m_angle);
	float y = std::sinf(m_angle);

	float distance = std::sqrtf(x*x + y*y);

	m_posX += m_velocity * x;
	m_posY += m_velocity * y;
}
