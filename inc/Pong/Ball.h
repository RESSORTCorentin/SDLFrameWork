#ifndef H_BALL
#define H_BALL

#include "../../inc/GameObject/SDLGameObject.h"
#include "../../inc/Pong/Vector2D.h"

class Ball : public SDLGameObject
{
private:
    Vector2D*    startPoint;
    bool         flagstouch;
public:
    virtual void update();
    virtual void render();

    Ball(LoadParams* pParams);
    ~Ball();
};


#endif