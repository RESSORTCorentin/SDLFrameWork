#ifndef H_PAUSESTATE
#define H_PAUSESTATE

#include <string>
#include <vector>
#include "GameState.h"
#include "SDLGameObject.h"

class PauseState : public GameState
{
private:
    static  const std::string s_pauseID;
    static  void s_pauseToMain();
    static  void s_resumePlay();

    std::vector<SDLGameObject*> m_gameObject;
public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const;
};

#endif