#include "player.h"

player::player()
{
	playerControlled(true);
	m_texture = new texture("./character.png");
}

void player::update()
{

}

void player::render()
{
	m_texture->render(pos(world));
}
