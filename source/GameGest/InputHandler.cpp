#include "../../inc/GameGest/InputHandler.h"
#include <iostream>
#include "../../inc/Pong/Game.h"

InputHandler*   InputHandler::s_pInstance = 0;

InputHandler::InputHandler() : m_keystate(0)
{
    for (int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
    m_mouseposition = new Vector2D(0, 0);
}

InputHandler* InputHandler::GetInstance()
{
    if (s_pInstance == nullptr)
    {
        s_pInstance = new InputHandler();
    }

    return (s_pInstance);
}

void    InputHandler::clean()
{
}

void    InputHandler::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            Game::Instance()->quit();
            break;
        case SDL_MOUSEMOTION:
            onMouseMove(event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            onMouseButtonDown(event);
            break;

        case SDL_MOUSEBUTTONUP:
            onMouseButtonUp(event);
            break;

        case SDL_KEYDOWN:
            onKeyDown();
            break;
        case    SDL_KEYUP:
            onKeyUp();
            break;
        default:
            break;
        }
    }
}

bool    InputHandler::getMouseButtonState(int buttonNumber)
{
  
    return m_mouseButtonStates[buttonNumber];
}

bool    InputHandler::isKeyDown(SDL_Scancode key)
{
    if (m_keystate != 0)
    {
        if (m_keystate[key] == 1)
        {
            return (true);
        }
    }
    return (false);
}

Vector2D*    InputHandler::getMousePosition()
{
    return (m_mouseposition);
}

void    InputHandler::onKeyDown()
{
    m_keystate =SDL_GetKeyboardState(0);
}
void    InputHandler::onKeyUp()
{
    m_keystate = SDL_GetKeyboardState(0);
}

void    InputHandler::onMouseMove(SDL_Event& event)
{
    m_mouseposition->setX(event.motion.x);
    m_mouseposition->setY(event.motion.y);
}

void    InputHandler::onMouseButtonDown(SDL_Event& event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = true;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = true;
    }
    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = true;
    }
}
void    InputHandler::onMouseButtonUp(SDL_Event& event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = false;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = false;
    }
    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = false;
    }
}

void InputHandler::reset()
{
	for(int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}