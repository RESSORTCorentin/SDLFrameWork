#include    "GameStateMachine.h"
#include    <iostream>
void    GameStateMachine::pushState(GameState* pState)
{
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void    GameStateMachine::popStatePrivate()
{
    if (!m_gameStates.empty())
    {
        if (m_gameStates.back()->onExit())
        {
            delete  m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
}

void    GameStateMachine::changeStatePrivate(GameState* pState)
{
    if (!m_gameStates.empty())
    {
        if (m_gameStates.back()->getStateID() == pState->getStateID())
        {
            return;
        }
        if (m_gameStates.back()->onExit())
        {
            delete  m_gameStates.back();
            m_gameStates.pop_back();
        }

        for (auto it = m_gameStates.begin(); it != m_gameStates.end(); it++)
        {
            if (((*it)->getStateID() == pState->getStateID()) && (*it)->onExit())
            {
                delete  (*it);
                m_gameStates.erase(it);
                break;
            }
        }
    }

    m_gameStates.push_back(pState);

    m_gameStates.back()->onEnter();
}

void    GameStateMachine::changeState(GameState* pState)
{
    changeStateFlag = true;
    newState = pState;
}

void    GameStateMachine::popState()
{
    popStateFlag = true;
}

void    GameStateMachine::update()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.back()->update();
    }

    if (changeStateFlag)
    {
        changeStatePrivate(newState);
        changeStateFlag = false;
    }

    else if(popStateFlag)
    {
        popStatePrivate();
        popStateFlag = false;
    }
    for (int i = 0; i < m_gameStates.size(); i++)
    {
        std::cout << m_gameStates[i]->getStateID() << std::endl;
    }
}

void    GameStateMachine::render()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.back()->render();
    }
}