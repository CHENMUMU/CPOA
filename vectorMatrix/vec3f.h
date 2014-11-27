#ifndef VEC3F_H
#define VEC3F_H

#include "vecteur.hpp"
#include "array.hpp"


class vec3f:public vecteur<float,3>
{
public:
    vec3f() : vecteur<float,3>(){}
    vec3f(float x, float y, float z);
    ~vec3f(){}

    float operator* (const vec3f& vec);
    vec3f operator^ (const vec3f& vec);

};

#endif // VEC3F_H
