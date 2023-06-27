#ifndef H_MENUSTATE
#define H_MENUSTATE

#include "GameState.h"
#include "SDLGameObject.h"
#include <vector>

class MenuState : public GameState
{
private:
    static  const   std::string s_menuID;
    static  void    s_menuToPlay();
    static  void    s_exitFromMenu();
    std::vector<SDLGameObject*> m_gameObject;
public:
    virtual void    update();
    virtual void    render();
    
    virtual bool    onEnter();
    virtual bool    onExit();

    
    virtual std::string getStateID() const {return (s_menuID);};

};



#endif