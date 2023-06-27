#ifndef H_VECTOR
#define H_VECTOR

#include <math.h>

class Vector2D
{
private:
    float m_x;
    float m_y;
public:
    Vector2D(float x, float y);

    float   getX();
    float   getY();

    void   setX(float x);
    void   setY(float y);

    float   length();

    Vector2D&   operator+=(const Vector2D& v2);
    Vector2D&   operator*=(const Vector2D& v2);
    Vector2D&   operator-=(const Vector2D& v2);
    Vector2D&   operator/=(const Vector2D& v2);

    Vector2D operator+(const Vector2D& v2);
    Vector2D operator*(float scalar);
    Vector2D operator-(const Vector2D& v2);
    Vector2D operator/(float scalar);
    void    normalize();
    Vector2D() {};
    ~Vector2D() {};
};

#endif