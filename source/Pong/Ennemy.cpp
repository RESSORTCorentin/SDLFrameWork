#include "../../inc/Pong/Ennemy.h"
#include "SDL2/SDL.h"
#include "../../inc/GameGest/InputHandler.h"

Ennemy::Ennemy(LoadParams* pParams) : SDLGameObject(pParams)
{

}

void    Ennemy::draw()
{
    SDLGameObject::draw();
}

void    Ennemy::update()
{
    Vector2D* ve = new Vector2D(*InputHandler::GetInstance()->getMousePosition());

    m_velocity = (*ve - m_position) / 10;
    SDLGameObject::update();
}   

void    Ennemy::clean()
{
    std::cout << "clean ennemy" << std::endl;
}