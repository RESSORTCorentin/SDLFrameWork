#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

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