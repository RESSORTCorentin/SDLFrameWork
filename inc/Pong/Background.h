#ifndef H_BACKGROUND
#define H_BACKGROUND

#include "../GameObject/SDLGameObject.h"

class Background : public SDLGameObject
{
private:
    /* data */
public:
    virtual void update();
    virtual void handleInput();
    virtual void clean();
    virtual void draw();
    
    Background(LoadParams* pParams);
    ~Background();
};

#endif