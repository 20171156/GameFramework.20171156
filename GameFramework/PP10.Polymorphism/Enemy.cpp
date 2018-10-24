#include "Enemy.h"

void Enemy::draw(SDL_Renderer * pRenderer)
{
    TextureManager::Instance()->drawFrame(m_textureID,
        m_x, m_y, m_width, m_height,
        m_currentRow, m_currentFrame, pRenderer);
}

void Enemy::update()
{
    GameObject::update();
	m_y += 1;
	//m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}