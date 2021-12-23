#include "player.h"

player::player()
{
	m_texture = new texture("./character.png");
}

void player::update()
{
}

void player::render()
{
	m_texture->render();
}
