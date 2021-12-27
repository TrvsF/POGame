#pragma once
#include "graphics.h"
#include "texture_helper.h"
#include <map>
/*----------
	asset manager class
	handles all game assets
	such as easy and safe texture loading

	a. travis 23rd dec
----------*/
class assets
{
	private:
		static assets* s_instance;
		
		std::map<std::string, SDL_Texture*> m_textures;

	public:
		static assets* INSTANCE();

		assets();
		~assets();

		SDL_Texture* getTexture(const char* path);
};
