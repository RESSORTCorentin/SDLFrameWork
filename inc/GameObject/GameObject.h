#ifndef H_GAMEOBJECT
#define H_GAMEOBJECT

#include <iostream>
#include "../GameGest/LoadParams.h"

class GameObject
{
private:
    /* data */
public:

    virtual void    draw() = 0;
    virtual void    update() = 0;
    virtual void    clean() = 0;

protected:
    GameObject (LoadParams* pParams) {};
    GameObject(){};
};


#endif
