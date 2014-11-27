#include "vec2f.h"


vec2f::vec2f(float x, float y) : vecteur<float,2>()
{
    this -> set(0,x);
    this -> set(1,y);
}


float vec2f :: operator* (const vec2f& vec)
{
    return (*this)[0]*vec[0] + (*this)[1]*vec[1];
}

int main()
{
    vec2f v5(4,8);
    vec2f v6(6,9);
    float v7 = v5 * v6;
    printf("v7:%f\n",v7);

}
