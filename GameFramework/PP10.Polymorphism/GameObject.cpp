#include "GameObject.h"

void GameObject::load(int x, int y, int width, int height,
	std::string textureID, SDL_RendererFlip flip)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;
	m_currentRow = 1;
	m_currentFrame = 1;
    m_flip = SDL_FLIP_NONE;
}

void GameObject::draw(SDL_Renderer* pRenderer)
{
    //원래는 drawframe이나 움직이는 이미지가 아니므로 draw로 교체
	TextureManager::Instance()->draw(m_textureID,
		m_x, m_y, m_width, m_height,
		pRenderer, m_flip);
}

void GameObject::update()
{
	m_x += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void GameObject::clean()
{
}
