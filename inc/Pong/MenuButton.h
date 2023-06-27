#ifndef H_MENUBUTTON
#define H_MENUBUTTON

#include "SDLGameObject.h"
#include <vector>



class MenuButton : public   SDLGameObject
{
private:
    void    (*m_callback)();
    bool    m_bReleased;

    enum    buttonState
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        MOUSE_CLICKED = 2
    };

public:
    MenuButton(LoadParams* pParams, void (*callback)());

    virtual void    update();
    virtual void    draw();
    virtual void    clean();
};

#endif