#include "../../inc/GameStates/MenuState.h"
#include "../../inc/GameStates/PlayerState.h"
#include "../../inc/GameStates/PauseState.h"
#include "Game.h"
#include "MenuButton.h"
#include "InputHandler.h"

const   std::string MenuState::s_menuID = "Menu";
void MenuState::update()
{
    if (m_gameObject.size())
    {
        for (int i = 0; i < m_gameObject.size(); i++)
        {
            m_gameObject[i]->update();
        }
    }
}

void    MenuState::render()
{
    for (int i = 0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->draw();
    }
}

bool    MenuState::onEnter()
{
    if (!TextureManager::Instance()->load("assets/exit.png", "exitbutton", Game::Instance()->getRenderer()))
    {
        std::cout << "Failed to load Exit\n" ;
        return (false);
    }

    if (!TextureManager::Instance()->load("assets/play.png", "playbutton", Game::Instance()->getRenderer()))
    {
        std::cout << "Failed to load Play\n" ;
        return (false);
    }

    SDLGameObject* button1 = new MenuButton(new LoadParams(100, 24, 100, 30, "playbutton"),s_menuToPlay);
    SDLGameObject* button2 = new MenuButton(new LoadParams(100, 70, 100, 30, "exitbutton"), s_exitFromMenu);

    m_gameObject.push_back(button1);
    m_gameObject.push_back(button2);
    std::cout << "entering MenuState" << std::endl;
    return (true);
}

bool    MenuState::onExit()
{
    for (int i = 0; i < m_gameObject.size(); i++)
    {
        m_gameObject[i]->clean();
    }
    m_gameObject.clear();
    TextureManager::Instance()->clearFromTextureMap("playbutton");
    TextureManager::Instance()->clearFromTextureMap("exitbutton");
    std::cout<< "Exiting Menustate" << std::endl;
    return (true);
}
void    MenuState::s_menuToPlay()
{
    std::cout << "Play button clicked" << std::endl;

    Game::Instance()->getStateMachine()->changeState(new PlayerState());
}

void    MenuState::s_exitFromMenu()
{
    Game::Instance()->quit();
    std::cout << "Exit Button  Clicked" << std::endl;
}