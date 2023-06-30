#include "../../inc/GameStates/PlayerState.h"
#include "../../inc/GameGest/TextureManager.h"
#include "../../inc/Pong/Game.h"
#include "../../inc/GameGest/InputHandler.h"
#include "../../inc/GameStates/PauseState.h"
#include "../../inc/Pong/Player.h"
#include "../../inc/Pong/Background.h"
#include "../../inc/Pong/Ball.h"
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
    if (!TextureManager::Instance()->load("assets/pongfond.png","fond", Game::Instance()->getRenderer()))
    {
        return (false);
    }

    if (!TextureManager::Instance()->load("assets/ballpong.png","ball", Game::Instance()->getRenderer()))
    {
        return (false);
    }

    if (!TextureManager::Instance()->load("assets/playerpong.png","player", Game::Instance()->getRenderer()))
    {
        return (false);
    }

    SDLGameObject* background = new Background(new LoadParams(0, 0, 799, 499, "fond"));
    SDLGameObject* ball = new Ball(new LoadParams(400, 250, 8, 8, "ball"));
    SDLGameObject* player1 = new Player(new LoadParams(10, 250, 2, 24, "player"), 0);
    SDLGameObject* player2 = new Player(new LoadParams(790, 250, 2, 24, "player"), 1);

    m_gameObject.push_back(background);
    m_gameObject.push_back(ball);
    m_gameObject.push_back(player1);
    m_gameObject.push_back(player2);
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
    TextureManager::Instance()->clearFromTextureMap("ball");
    TextureManager::Instance()->clearFromTextureMap("fond");
    std::cout<< "Exiting PlayerState" << std::endl;
    return (true);
}

std::string PlayerState::getStateID() const
{
    return (s_PlayerID);
}