#include <SDL2/SDL.h>
#include "Game.h"

Game* g_game = 0;
const   int FPS = 60;
const   int DELAY_TIME = 1000.0f / FPS;

int main(int argc,char **argv)
{
    Uint32  frameStart, frameTime;

    if (Game::Instance()->init("Pong", 100, 100, 400, 600, 0))
    {
        while (Game::Instance()->running())
        {

            frameStart =SDL_GetTicks();
            Game::Instance()->handleEvent();
            Game::Instance()->render();
            Game::Instance()->update();

            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < DELAY_TIME)
            {
                SDL_Delay((int)DELAY_TIME - frameTime);
            }
        }
        Game::Instance()->clean();
    }

    return (0);
}