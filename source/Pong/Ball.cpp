#include "../../inc/Pong/Ball.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Ball::Ball(LoadParams* pParams) : SDLGameObject(pParams)
{
    srand(time(NULL));
    int choice  = rand() %  100 + 1;
    if (choice > 150)
    {
        m_angx = 45/(rand() % 44 + 1) ;
        m_angy = -1;
        m_signeY = -1;
    }
    else
    {
        m_angx = 1;
        m_angy = 45/(rand() % 44 + 1);
        m_signeY = 1;
    }
    m_signeX = 1;
    std::cout << choice << std::endl;
    m_dist_x = 0;
    m_dist_y =0;
}

void Ball::update()
{

    if (m_position.getY() < 1 || m_position.getY() > 499)
    {
        if (m_position.getY() < 1)
        {
            m_signeY = 1;
        }
        if (m_position.getY() > 499)
        {
            m_signeY = -1;
        }
        m_angl = getAngle(m_dist_x, sqrtf(powf(m_dist_x, 2) + powf(m_dist_y, 2)));
        if (m_angl > 45)
        {
            m_angx = m_angl / 45;
            m_angy = 1;
        }
        if (m_angl < 45)
        {
            m_angx = 1;
            m_angy = m_angl / 45;
        }
        if (m_angl == 45)
        {
            m_angx = 1;
            m_angy = 1;
        }
        m_dist_x = 0;
        m_dist_y =0;
    }
    if (m_position.getX() < 0 || m_position.getX() > 800)
    {
        if (m_position.getX() < 0)
        {
            m_signeX = 1;
        }
         if (m_position.getX() > 800)
        {
            m_signeX  = -1;
        }
        m_angl = getAngle(m_dist_y, sqrtf(powf(m_dist_x, 2) + powf(m_dist_y, 2)));
        if (m_angl > 45)
        {
            m_angx = m_angl / 45;
            m_angy = 1;
        }
        if (m_angl < 45)
        {
            m_angx = 1;
            m_angy = m_angl / 45;
        }
        if (m_angl == 45)
        {
            m_angx = 1;
            m_angy = 1;
        }
        m_dist_x = 0;
        m_dist_y =0;
    }
    m_dist_x += m_angx;
    m_dist_y += m_angy; 
    m_velocity.setX((m_angx * m_signeX));
    m_velocity.setY((m_angy * m_signeY));
    SDLGameObject::update();
}

void Ball::draw()
{
    SDLGameObject::draw();
}

float    Ball::getAngle(float adj, float hyp)
{
    return (acos(adj / hyp) * 180 / 3.14159);
}

float   Ball::getDistX()
{
    return (m_dist_x);
}

float   Ball::getDistY()
{
    return (m_dist_y);
}

void   Ball::setDistY(float x)
{
    m_dist_x = x;
}

void   Ball::setDistX(float y)
{
    m_dist_y = y;
}

bool    Ball::getSigne()
{
    return (m_signeY);
}

void     Ball::setSigneX(int i)
{
    m_signeX = i;
}

void    Ball::reset()
{
    m_position.setX(400);
    m_position.setY(250);
    srand(time(NULL));
    int choice  = rand() %  100 + 1;
    if (choice > 100)
    {
        m_angx = 45/(rand() % 44 + 1) ;
        m_angy = -1;
        m_signeY = -1;
    }
    else
    {
        m_angx = 1;
        m_angy = 45/(rand() % 44 + 1);
        m_signeY = 1;
    }
    if ((rand() % 2 + 1) == 2)
    {
        m_signeX = 1;
    }
    else 
    {
        m_signeX = -1;
    }
    m_dist_x = 0;
    m_dist_y =0;
    
}