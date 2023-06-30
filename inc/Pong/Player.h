#ifndef H_PLAYER
#define H_PLAYER

#include "../GameObject/SDLGameObject.h"

class Player : public SDLGameObject
{
private:
    int numPlay;
public:
    Player(){};
    Player(LoadParams* pParams, int numPlay);
    ~Player();
    void    draw();
    void    update();
    void    clean();
    void    handleInput();
};



#endif