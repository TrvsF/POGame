#pragma once
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
		std::map<std::string, SDL_Texture*> m_textStrings;
		std::map<std::string, TTF_Font*> m_fonts;

		TTF_Font* getFont(std::string path, int size);

	public:
		static assets* INSTANCE();

		assets();
		~assets();

		SDL_Texture* getTexture(std::string path);
		SDL_Texture* getText(std::string text, std::string path, int size, SDL_Color colour);
};
