#include "Ball.h"
#include "InputHandler.h"

Ball::Ball(const LoaderParams * pParams) : SDLGameObject(pParams)
{

}


void Ball::handleInput()
{

}


void Ball::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Ball::update()
{
	m_velocity.setX(1);
}

void Ball::clean()
{

}

