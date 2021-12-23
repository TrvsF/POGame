#pragma once
#include "graphics.h"
#include <map>

class asset_manager
{

	private:
		static asset_manager* s_instance;
		
		std::map<std::string, SDL_Texture*> m_textures;

	public:
		static asset_manager* INSTANCE();

		asset_manager();
		~asset_manager();

		SDL_Texture* getTexture(const char* path);

};
