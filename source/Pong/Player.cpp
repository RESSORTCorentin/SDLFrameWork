#include "../../inc/Pong/Player.h"
#include "SDL2/SDL.h"
#include "../../inc/GameGest/InputHandler.h"

Player::Player(LoadParams* pParams) : SDLGameObject(pParams)
{

}

void    Player::draw()
{
    SDLGameObject::draw();
}

void    Player::update()
{

    m_currentFrame = 5;
    handleInput();
    
    SDLGameObject::update();

}

void    Player::handleInput()
{
    if (InputHandler::GetInstance()->isKeyDown(SDL_SCANCODE_Q))
    {
        m_velocity.setX(1);
    }
    else
    {
        m_velocity.setX(0);
        m_velocity.setY(0);
    }
}

void    Player::clean()
{
    
}