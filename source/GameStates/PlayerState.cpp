#include "../../inc/GameStates/PlayerState.h"
#include "../../inc/GameGest/TextureManager.h"
#include "../../inc/Pong/Game.h"
#include "../../inc/GameGest/InputHandler.h"
#include "../../inc/GameStates/PauseState.h"
#include "../../inc/Pong/Player.h"
#include <iostream>

const   std::string PlayerState::s_PlayerID = "Player";

void PlayerState::update()
{
    std::cout << "entering PlayerState update" << std::endl;
    if (InputHandler::GetInstance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    }
    for (int i = 0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->update();
    }
}

void    PlayerState::render()
{
    for (int i = 0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->draw();
    }
    std::cout << "entering PlayerState render" << std::endl;
}

bool    PlayerState::onEnter()
{
    if (!TextureManager::Instance()->load("assets/viking.bmp","viking", Game::Instance()->getRenderer()))
    {
        return (false);
    }
    SDLGameObject* player = new Player(new LoadParams(100, 100, 20, 20, "viking"));
    m_gameObject.push_back(player);
    std::cout << "entering PlayerState" << std::endl;
    return (true);
}

bool    PlayerState::onExit()
{
    for (int i = 0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->clean();
    }
    m_gameObject.clear();
    TextureManager::Instance()->clearFromTextureMap("viking");
    std::cout<< "Exiting PlayerState" << std::endl;
    return (true);
}

std::string PlayerState::getStateID() const
{
    return (s_PlayerID);
}