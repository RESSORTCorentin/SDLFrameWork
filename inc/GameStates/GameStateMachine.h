#ifndef H_GAMESTATEMACHINE
#define H_GAMESTATEMACHINE

#include    "GameState.h"
#include    <vector>

class GameStateMachine
{
private:
    std::vector<GameState*> m_gameStates;
    void    popStatePrivate();
    void    changeStatePrivate(GameState* pState);
    GameState*  newState;
    bool        popStateFlag;
    bool        changeStateFlag;
public:
    GameStateMachine() : newState(nullptr), popStateFlag(false), changeStateFlag(false){};
    void    pushState(GameState* pState);
    void    changeState(GameState* pState);
    void    popState();

    void    update();
    void    render();
};



#endif