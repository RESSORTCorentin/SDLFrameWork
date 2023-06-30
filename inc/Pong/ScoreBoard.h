#ifndef H_SCOREBOARD
#define H_SCOREBOARD

#include "../../inc/GameObject/SDLGameObject.h"

class ScoreBoard : public SDLGameObject
{
private:

public:
    virtual void update();
    virtual void draw();
    void    setFrame(int i);
    ScoreBoard(LoadParams* pParams);
    ~ScoreBoard();
};

#endif