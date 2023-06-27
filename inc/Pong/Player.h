#ifndef H_PLAYER
#define H_PLAYER

#include "../GameObject/SDLGameObject.h"

class Player : public SDLGameObject
{
private:
    /* data */
public:
    Player(){};
    Player(LoadParams* pParams);
    ~Player();
    void    draw();
    void    update();
    void    clean();
    void    handleInput();
};



#endif