#include "GameOverState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "LoadParams.h"
#include "PlayerState.h"
#include "MenuState.h"

std::string const   m_stateID = "GAMEOVER";

void    GameOverState::update()
{
    for (int i = 0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->update();
    }
}

void    GameOverState::render()
{
 
    for (int i = 0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->draw();
    }
}

bool    GameOverState::onEnter()
{
    if (!TextureManager::Instance()->load("assets/retry.png", "retry", Game::Instance()->getRenderer()))
    {
        return (false);
    }

    if (!TextureManager::Instance()->load("assets/menu.png", "menu", Game::Instance()->getRenderer()))
    {
        return (false);
    }

    SDLGameObject* retry = new MenuButton(new LoadParams(100, 100, 100, 30, "retry"), s_goToPlay);
    SDLGameObject* menu  = new MenuButton(new LoadParams(100, 150, 100, 30, "menu"), s_goToMenu);

    m_gameObject.push_back(retry);
    m_gameObject.push_back(menu);

    return (true);
}

bool    GameOverState::onExit()
{
    for (int i  = 0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->clean();
    }
    m_gameObject.clear();
    TextureManager::Instance()->clearFromTextureMap("retry");
    TextureManager::Instance()->clearFromTextureMap("menu");

    return (true);
}

void    GameOverState::s_goToplay()
{
    Game::Instance()->getStateMachine()->changeState(new PlayerState());
}

void    GameOverState::s_gotToMenu()
{
    Game::Instance()->getStateMachine()->changeState(new MenuState());
}