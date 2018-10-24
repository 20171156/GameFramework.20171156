#include "Monster.h"
#include "Window.h"

Monster::Monster(int _speed)
{ 
    speed = _speed;
}

Monster::~Monster()
{

}

void Monster::update()
{
    /*스프라이트 프레임을 조정하는 내용
    if (befortime + (1000/60) <= SDL_GetTicks())
    {
        m_x += speed;
        befortime = SDL_GetTicks();
    }
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));*/

    if (m_x > WINDOW_WIDTH - 100)
    {
        left = true;
    }
    else if (m_x < 0)
    {
        left = false;
    }

    if (left == true)
    {
        m_x -= speed;
        m_flip = SDL_FLIP_HORIZONTAL;
    }
    else
    { 
        m_x += speed;
        m_flip = SDL_FLIP_NONE;
    }
}

//game.cpp에서 접근하지 못함. 이유는?
//void Monster::setSpeed()
//{
//  speed = _speed;
//}
