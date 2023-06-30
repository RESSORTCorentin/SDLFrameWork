#include "../../inc/GameObject/SDLGameObject.h"
#include "../../inc/GameGest/TextureManager.h"
#include "../../inc/Pong/Game.h"

SDLGameObject::SDLGameObject(LoadParams* pParams) : GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0,0), m_accelaration(0,0)
{
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTexture();

    m_currentFrame = 1;
    m_currentRow = 1;
}

void    SDLGameObject::draw()
{
    TextureManager::Instance()->draw(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height,Game::Instance()->getRenderer());
}

void    SDLGameObject::drawFrame()
{
    TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer());

}

void    SDLGameObject::update()
{
    m_velocity += m_accelaration;
    m_position += m_velocity;
}

void    SDLGameObject::clean()
{

}

float   SDLGameObject::getPosX()
{
    return(m_position.getX());
}

float   SDLGameObject::getPosY()
{
    return(m_position.getY());
}

float   SDLGameObject::getWidth()
{
    return(m_width);
}
float   SDLGameObject::getHeight()
{
    return(m_height);
}