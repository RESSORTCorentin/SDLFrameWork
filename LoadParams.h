#ifndef H_LOADPARMS
#define H_LOADPARMS

#include <iostream>

class LoadParams
{
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    std::string m_textureID;

public:
    LoadParams(int x, int y, int width, int height, std::string textureID);
    int const getX();
    int const getY();
    int const getWidth();
    int const getHeight();
    std::string const getTexture();
    ~LoadParams();
};

#endif