#ifndef H_GAME
#define H_GAME

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "../GameGest/TextureManager.h"
#include "../GameObject/GameObject.h"
#include "../GameStates/GameStateMachine.h"
#include "Player.h"
#include "Ennemy.h"

enum    games_states
{
        MENU = 0,
        PLAY = 1,
        GAMEOVER = 2
};

class Game
{
public:
        ~Game();
        void render();
        void update();
        void handleEvent();
        void clean();
        void draw();
        void quit();
        bool init(const char* titre, int posx, int posy, int height, int width, int flags);
        bool running();
        static Game* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
                return (s_pInstance);
	};
        GameStateMachine* getStateMachine();
        SDL_Renderer* getRenderer();
private:
        Game();
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRender;

        GameStateMachine* m_pGameStateMachine;
        bool m_bRunning;
        static  Game* s_pInstance;
};

#endif

