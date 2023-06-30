#include <iostream>
#include "inc/Pong/Game.h"

// our Game object
Game* g_game = 0;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main()
{
	Uint32 frameStart, frameTime;
	
	std::cout << "game init attempt..." << std::endl;
	if(Game::Instance()->init("Pong", 100, 100, 500, 800, false))
	{
		std::cout << "game init success!\n";
		while(Game::Instance()->running())
		{
			frameStart = SDL_GetTicks();
			
			Game::Instance()->handleEvent();
			Game::Instance()->update();
			Game::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			if(frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << std::endl;
		return -1;
	}
	
	std::cout << "game closing..." << std::endl;
	Game::Instance()->clean();

	return 0;
}


