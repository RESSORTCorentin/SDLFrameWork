#ifndef H_ENNEMY
#define H_ENNEMY

#include "../GameObject/SDLGameObject.h"

class Ennemy : public SDLGameObject
{
private:
    /* data */
public:
    Ennemy(LoadParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};


#endif