#include "../../inc/GameStates/GameOverState.h"
#include "../../inc/GameGest/TextureManager.h"
#include "../../inc/Pong/Game.h"
#include "../../inc/Pong/MenuButton.h"
#include "../../inc/GameGest/LoadParams.h"
#include "../../inc/GameStates/PlayerState.h"
#include "../../inc/GameStates/MenuState.h"

const   std::string GameOverState::s_GameOverID = "GAMEOVER";

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
        m_gameObject[i]->drawFrame();
        std::cout << "entering PlayerState" << std::endl;
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

    SDLGameObject* retry = new MenuButton(new LoadParams(100, 100, 100, 30, "retry"), s_GameOverToPlay);
    SDLGameObject* menu  = new MenuButton(new LoadParams(100, 150, 100, 30, "menu"), s_GameOverToMenu);

    m_gameObject.push_back(retry);
    m_gameObject.push_back(menu);
    std::cout << "entering OverState"  << m_gameObject.size() << std::endl;
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

void    GameOverState::s_GameOverToPlay()
{
    Game::Instance()->getStateMachine()->changeState(new PlayerState());
}

void    GameOverState::s_GameOverToMenu()
{
    Game::Instance()->getStateMachine()->changeState(new MenuState());
}
