#pragma once
#include "GameObject.h"

class Monster : public GameObject 
{
public:
    Monster(int _speed);
    ~Monster();
    //void load(int x, int y, int width, int height,
    //std::string textureID);
    //void draw(SDL_Renderer* pRenderer);
    void update();
    //void clean();

    //void setSpeed();

    bool left = true;
    int speed = 0;
    int befortime = 0;

};