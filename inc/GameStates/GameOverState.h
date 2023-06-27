#ifndef H_GAMEOVERSTATE
#define H_GAMEOVERSTATE

#include "GameState.h"
#include "SDLGameObject.h"
#include <vector>

class GameOverState : public GameState
{
private:
    static const std::string m_stateID;
    std::vector<SDLGameObject*> m_gameObject;
public:
    virtual void    update();
    virtual void    render();

    virtual bool    onEnter();
    virtual bool    onExit();

    virtual std::string getStateID();


    static  void    s_goToplay();
    static  void    s_gotToMenu();
    
    GameOverState(/* args */);
    ~GameOverState();
};

#endif