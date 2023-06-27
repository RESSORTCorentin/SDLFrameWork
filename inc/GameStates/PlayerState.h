#ifndef H_PLAYERSTATE
#define H_PLAYERSTATE

#include <vector>
#include "GameState.h"
#include "SDLGameObject.h"

class   GameObject;

class PlayerState : public GameState
{
private:
    static  const   std::string s_PlayerID;
    std::vector<SDLGameObject*> m_gameObject;
public:
    virtual void    update();
    virtual void    render();
    
    virtual bool    onEnter();
    virtual bool    onExit();

    virtual std::string getStateID() const;
    PlayerState(/* args */){};
    ~PlayerState(){};
};


#endif