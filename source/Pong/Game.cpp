#include "../../inc/Pong/Game.h"
#include "../../inc/GameGest/InputHandler.h"
#include "../../inc/GameStates/MenuState.h"
#include "../../inc/GameStates/PlayerState.h"
#include "../../inc/GameStates/PauseState.h"


using namespace std;

Game* Game::s_pInstance = 0;

Game::Game()
{

}
bool    Game::init(const char* titre, int xpos, int ypos, int height, int width, int flags)
{
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL init Success" << endl;
       if ((m_pWindow = SDL_CreateWindow(titre, xpos, ypos, width, height, flags)))
        {
            cout << "SDL Window init Success" << endl;
            if ((m_pRender = SDL_CreateRenderer(m_pWindow, -1,0)))
            {
                cout << "SDL Render Success" << endl;
                SDL_SetRenderDrawColor(m_pRender, 0, 0, 0, 255);
                
            }
            else
            {
                cout << "SDL Render Failed" << endl;
                return (false);
            }
        }
       else
        {
            cout << "SDL Window Failed" << endl;
            return (false);
        }
    }
    else 
    {
        cout << "SDL init Failed" << endl;
        return (false);
    }
    m_bRunning = true;

    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());

    return (true);
}

void    Game::render()
{
    SDL_RenderClear(m_pRender);
    m_pGameStateMachine->render();
    SDL_RenderPresent(m_pRender);
}

void    Game::clean()
{
    cout << "cleaning game\n" << endl;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRender);
    InputHandler::GetInstance()->clean();
    SDL_Quit();
}

void    Game::update()
{
    m_pGameStateMachine->update();
}

void    Game::handleEvent()
{
    InputHandler::GetInstance()->update();
    if(InputHandler::GetInstance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		getStateMachine()->changeState(new PlayerState());
	}
}

bool    Game::running()
{
    return (m_bRunning);
}

SDL_Renderer*   Game::getRenderer()
{
    return (m_pRender);
}

void    Game::quit()
{
    m_bRunning = false;
}

GameStateMachine*   Game::getStateMachine()
{
    return (m_pGameStateMachine);
}

Game::~Game(){
    delete s_pInstance;
    delete m_pGameStateMachine;
}