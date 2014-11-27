#include "vec3f.h"


vec3f::vec3f(float x, float y,float z) : vecteur<float,3>()
{
    this -> set(0,x);
    this -> set(1,y);
    this -> set(2,z);
}


float vec3f :: operator* (const vec3f& vec)
{
    return (*this)[0] * vec[0] +  (*this)[1] * vec[1] + (*this)[2] * vec[2];
}


vec3f vec3f::operator^ (const vec3f& vec)
{
   return vec3f ( (*this)[1] * vec[2] - (*this)[2] * vec[1],
                  (*this)[2] * vec[0] - (*this)[0] * vec[2],
                  (*this)[0] * vec[1] - (*this)[1] * vec[0] );

}

int main()
{
    vec3f v1(7.3,5.2,6.4);
    vec3f v2(1,2,6);

    vec3f v3 = v1 ^ v2;
    float v4 = v1 * v2;
    return 0;
}
