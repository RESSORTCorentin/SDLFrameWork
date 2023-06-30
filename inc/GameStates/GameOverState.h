#ifndef H_GAMEOVERSTATE
#define H_GAMEOVERSTATE

#include "GameState.h"
#include "../GameObject/SDLGameObject.h"
#include <vector>

class GameOverState : public GameState
{
private:
    static const std::string s_GameOverID;
    std::vector<SDLGameObject*> m_gameObject;
    static  void    s_goToPlay();
    static  void    s_goToMenu();
    ~GameOverState();
public:
    virtual void    update();
    virtual void    render();

    virtual bool    onEnter();
    virtual bool    onExit();

    virtual std::string getStateID() const
    {
        return (s_GameOverID);
    };
};

#endif