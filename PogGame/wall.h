#pragma once
#include "game_entity.h"
#include "texture.h"

class wall : public game_entity
{
	private:
		texture* m_texture;
};