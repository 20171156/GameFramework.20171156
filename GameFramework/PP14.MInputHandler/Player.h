#pragma once
#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
    void handleInput();
public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};