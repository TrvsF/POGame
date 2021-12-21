#include "player_object.h"
#include "texture_manager.h"

player_object::player_object(const char* texturesheet, SDL_Renderer* renderer, int x, int y)
{
	localRenderer = renderer;
	objTexture = texture_manager::loadTexture(texturesheet, localRenderer);

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	xPos = 400;
	yPos = 300;

	/*
		0 = forward
		1 = backward
		2 = left
		3 = right

		DONT DO THIS AS A FOR LOOP IT BREAKS EVERYTHING!!!
	*/
	movementVect[0] = 0;
	movementVect[1] = 0;
	movementVect[2] = 0;
	movementVect[3] = 0;

	angle = 0;
	moveVelocity = 0;
}

player_object::~player_object()
{

}

void player_object::update()
{
	printf("angle : %f, moveVel : %f, coords : %f,%f\n", angle, moveVelocity, xPos, yPos);

	handleMovement();
	handleTurning();

	moveToPoint();

}

void player_object::render()
{
	SDL_Rect dstRect;

	dstRect.x = xPos;
	dstRect.y = yPos;
	SDL_QueryTexture(objTexture, NULL, NULL, &dstRect.w, &dstRect.h);
	dstRect.x -= (dstRect.w / 2);
	dstRect.y -= (dstRect.h / 2);

	double textureAngle = (angle + M_PI/2) * 180 / M_PI;

	SDL_RenderCopyEx(localRenderer, objTexture, NULL, &dstRect, textureAngle, NULL, SDL_FLIP_NONE);
}

void player_object::handleTurning()
{
	// if moving forward key is down 
	if (movementVect[2] == 1)
	{
		angle -= 0.003;
	}

	// if moving backward key is down
	if (movementVect[3] == 1)
	{
		angle += 0.003;
	}
}

void player_object::handleMovement()
{
	// if moving forward key is down 
	if (movementVect[0] == 1)
	{
		if (moveVelocity >= 0.5)
		{
			moveVelocity = 0.5;
		}
		else
		{
			moveVelocity += 0.0005;
		}
	}

	// if moving backward key is down
	if (movementVect[1] == 1)
	{
		if (moveVelocity <= -0.5)
		{
			moveVelocity = -0.5;
		}
		else
		{
			moveVelocity -= 0.0005;
		}
	}

	// if neither
	if (movementVect[0] == 0 && movementVect[1] == 0)
	{
		moveVelocity = 0;
	}
}

void player_object::moveToPoint()
{
	float x = std::cosf(angle);
	float y = std::sinf(angle);

	float distance = std::sqrtf(x*x + y*y);

	xPos += moveVelocity * x;
	yPos += moveVelocity * y;
}
