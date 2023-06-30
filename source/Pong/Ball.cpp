#include "../../inc/Pong/Ball.h"

Ball::Ball(LoadParams* pParams) : SDLGameObject(pParams)
{
    startPoint = new Vector2D((float)pParams->getX(), (float)pParams->getY());
    flagstouch = false;
}

void Ball::update()
{
    if (flagstouch == false)
    {
        m_velocity.setX(0.56);
        m_velocity.setY(0.10);
        std::cout << "Longueur Vecteur  :" << Vector2D(m_position.getX() - startPoint->getX(), m_position.getY() - startPoint->getY()).length() << std::endl;
        std::cout << "Longueur Vecteur2 :" << m_position.getX() - startPoint->getX() << std::endl;
        std::cout << "Longueur Vecteur3 :" << m_position.getY() - startPoint->getY() << std::endl;
        if (m_position.getX() == 500)
        {
            
        }
    }
    SDLGameObject::update();
}

void Ball::render()
{
    SDLGameObject::draw();
}
