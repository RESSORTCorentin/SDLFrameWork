#include "../../inc/GameGest/LoadParams.h"

LoadParams::LoadParams(int x, int y, int width, int height, std::string textureID) : m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID)
{

}

int const LoadParams::getX()
{
    return (m_x);
}

int const LoadParams::getY()
{
    return (m_y);
}

int const LoadParams::getHeight()
{
    return (m_height);
}

int const LoadParams::getWidth()
{
    return (m_width);
}

std::string const LoadParams::getTexture()
{
    return(m_textureID);
}