#ifndef VEC2F_H
#define VEC2F_H

#include "vec3f.h"
#include "vecteur.hpp"


class vec2f : public vecteur<float,2>
{
public:

    vec2f() : vecteur<float,2>(){}
    vec2f(float x, float y);
    ~vec2f(){}


    //operator
    float operator* (const vec2f& vec);

   // float& vec_x = m_data[0], vec_y = m_data[1];

    
    
};

#endif // VEC2F_H
