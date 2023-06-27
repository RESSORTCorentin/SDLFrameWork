#include "MenuButton.h"
#include "Vector2D.h"
#include "InputHandler.h"
#include "PlayerState.h"
#include "Game.h"

MenuButton::MenuButton(LoadParams* pParams, void (*callback)()) : SDLGameObject(pParams), m_callback(callback)
{
    m_currentFrame = MOUSE_OUT;
}

void    MenuButton::draw()
{
    SDLGameObject::draw();
}

void    MenuButton::update()
{
    Vector2D* mousePos = InputHandler::GetInstance()->getMousePosition();
    
    if (mousePos->getX() < (m_position.getX() + m_width)
    && mousePos->getX() > m_position.getX()
    && mousePos->getY() < (m_position.getY() + m_height)
    && mousePos->getY() > m_position.getY())
    {
        if (InputHandler::GetInstance()->getMouseButtonState(LEFT) && m_bReleased)
        {
            m_currentFrame = MOUSE_CLICKED;
            m_callback();
            m_bReleased = false;
        }
        else if (!InputHandler::GetInstance()->getMouseButtonState(LEFT))
        {
            m_bReleased = true;
            m_currentFrame = MOUSE_OVER;
        }
    }
    else
    {
        m_currentFrame = MOUSE_OUT;
    }
}

void    MenuButton::clean()
{
    SDLGameObject::clean();
}