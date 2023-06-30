#include "../../inc/Pong/Player.h"
#include "SDL2/SDL.h"
#include "../../inc/GameGest/InputHandler.h"

Player::Player(LoadParams* pParams,int numPlay) : SDLGameObject(pParams), numPlay(numPlay)
{
    //m_accelaration.setY(-20);
}

void    Player::draw()
{
    SDLGameObject::draw();
}

void    Player::update()
{

    handleInput();
    
    SDLGameObject::update();

}

void    Player::handleInput()
{
    if (numPlay == 0)
    {
        if (InputHandler::GetInstance()->isKeyDown(SDL_SCANCODE_Z) && m_position.getY() < 475)
        {
            m_velocity.setY(1);
        }

        else if (InputHandler::GetInstance()->isKeyDown(SDL_SCANCODE_S) && m_position.getY() > 1)
        {
            m_velocity.setY(-1);
        }
        else
        {
             m_velocity.setY(0);
        }
    }   
    else if (numPlay == 1)
    {
        if (InputHandler::GetInstance()->isKeyDown(SDL_SCANCODE_DOWN) && m_position.getY() < 475)
        {
            m_velocity.setY(1);
        }

        else if (InputHandler::GetInstance()->isKeyDown(SDL_SCANCODE_UP) && m_position.getY() > 1)
        {
            m_velocity.setY(-1);
        }
        else
        {
             m_velocity.setY(0);
        }
    }   
   
}

void    Player::clean()
{
    
}