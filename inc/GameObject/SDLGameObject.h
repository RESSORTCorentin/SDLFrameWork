#ifndef H_SDLGAMEO
#define H_SDLGAMEO

#include "Vector2D.h"
#include "GameObject.h"
#include "LoadParams.h"

class SDLGameObject : public GameObject
{
private:
    /* data */
public:
    SDLGameObject(LoadParams* pParams);

    virtual void    draw();
    virtual void    update();
    virtual void    clean(); 

protected:

    SDLGameObject(){};
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_accelaration;
    

    int m_width;
    int m_height;

    int m_currentRow;
    int m_currentFrame;

    std::string m_textureID;
};

#endif