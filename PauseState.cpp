#include "PauseState.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "LoadParams.h"
#include "Game.h"

const  std::string PauseState::s_pauseID = "PAUSE";

void    PauseState::s_pauseToMain()
{
    Game::Instance()->getStateMachine()->changeState(new MenuState());
}

void    PauseState::s_resumePlay()
{
    Game::Instance()->getStateMachine()->popState();
}

void    PauseState::update()
{
    std::cout << "entering PauseState update" << std::endl;
    for (int i =0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->update();
    }
}

void    PauseState::render()
{
    std::cout << "entering PauseState render" << std::endl;
    for (int i = 0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->draw();
    }
}

bool    PauseState::onEnter()
{
    if (!TextureManager::Instance()->load("assets/pause.png", "resume", Game::Instance()->getRenderer()))
    {
        return (false);
    }
    if (!TextureManager::Instance()->load("assets/menu.png", "mainbutton", Game::Instance()->getRenderer()))
    {
        return (false);
    }

    SDLGameObject* button1 = new MenuButton(new LoadParams(200, 200, 100, 30, "mainbutton"), s_pauseToMain);
    SDLGameObject* button2 = new MenuButton(new LoadParams(200, 250, 100, 30, "resume"), s_resumePlay);

    m_gameObject.push_back(button1);
    m_gameObject.push_back(button2);

    std::cout << "entering PauseState\n" << std::endl;
    return (true);
}

bool    PauseState::onExit()
{
    for (int i = 0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->clean();
    }
    m_gameObject.clear();
    TextureManager::Instance()->clearFromTextureMap("resume");
    TextureManager::Instance()->clearFromTextureMap("mainbutton");

    InputHandler::GetInstance()->reset();
    std::cout << "Exiting PauseState" << std::endl;
    return (true);
}

std::string PauseState::getStateID() const 
{
    return s_pauseID;
}