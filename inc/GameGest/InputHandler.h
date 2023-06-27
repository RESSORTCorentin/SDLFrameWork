#ifndef H_INPUTHANDLER
#define H_INPUTHANDLER

#include <vector>
#include "SDL2/SDL.h"
#include "../Pong/Vector2D.h"
enum    mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler
{
private:
    InputHandler(/* args */);
    ~InputHandler(){};
    const Uint8*   m_keystate;
    std::vector<bool> m_mouseButtonStates;
    static InputHandler*    s_pInstance;
    Vector2D* m_mouseposition;

    void    onKeyDown();
    void    onKeyUp();
    void    onMouseMove(SDL_Event& event);
    void    onMouseButtonDown(SDL_Event& event);
    void    onMouseButtonUp(SDL_Event& event);
public:
    
    Vector2D*    getMousePosition();
    
    bool    getMouseButtonState(int buttonNumber);
    bool    isKeyDown(SDL_Scancode key);
    bool    isKeyPress(SDL_Scancode key);
    void    clean();
    void    update();
    void reset();
    static InputHandler* GetInstance();
};

#endif