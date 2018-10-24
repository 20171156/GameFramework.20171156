#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.h"

class GameObject
{
public:
	virtual void load(int x, int y, int width, int height,
		std::string textureID, SDL_RendererFlip flip );
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();


protected:
    SDL_RendererFlip m_flip;
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;

};