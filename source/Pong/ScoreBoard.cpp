#include "../../inc/Pong/ScoreBoard.h"

ScoreBoard::ScoreBoard(LoadParams* pParams) : SDLGameObject(pParams)
{
    SDLGameObject::m_currentFrame = 0;
}

void    ScoreBoard::update()
{
    SDLGameObject::update();
}

void    ScoreBoard::draw()
{
    SDLGameObject::drawFrame();
}


void    ScoreBoard::setFrame(int i)
{
    SDLGameObject::m_currentFrame = i;
}