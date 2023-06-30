#ifndef H_BALL
#define H_BALL

#include "../../inc/GameObject/SDLGameObject.h"
#include "../../inc/Pong/Vector2D.h"

class Ball : public SDLGameObject
{
private:
    int          m_signeX;
    int          m_signeY;

    float        m_angx;
    float        m_angy;
    float        m_dist_x;
    float        m_dist_y;

    Vector2D*   startPos;
    float        m_angl;
    float        accel;
    float       getAngle(float adj, float hyp);
public:
    virtual void update();
    virtual void draw();
    float   getDistX();
    float   getDistY();
    void   setDistY(float y);
    void   setDistX(float x);
    bool    getSigne();
    void     setSigneX(int i);
    void    reset();
    Ball(LoadParams* pParams);
    ~Ball();
};


#endif