#ifndef H_SDLGAMEO
#define H_SDLGAMEO

#include "../Pong/Vector2D.h"
#include "GameObject.h"
#include "../GameGest/LoadParams.h"

class SDLGameObject : public GameObject
{
private:
    /* data */
public:
    SDLGameObject(LoadParams* pParams);

    virtual void    draw();
    virtual void    update();
    virtual void    clean(); 
    virtual void    drawFrame();
    virtual float   getPosX();
    virtual float   getPosY();
    virtual float   getWidth();
    virtual float   getHeight();
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