#include "Player.h"
#include "InputHandler.h"
#include "Game.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        m_velocity.setX(10);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_velocity.setX(-10);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        m_velocity.setY(-10);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_velocity.setY(10);
    }

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		TheGame::Instance()->getGameObjects().push_back(new Ball(new LoaderParams(20, 20, 50, 50, "ball")));
		//m_gameObjects.push_back(new Ball(new LoaderParams(20, 20, 50, 50, "ball")));
	}

}

void Player::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    //m_acceleration.setX(1);
    SDLGameObject::update();
}

void Player::clean()
{
}