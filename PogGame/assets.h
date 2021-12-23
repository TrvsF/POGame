#pragma once
#include "graphics.h"
#include <map>

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
