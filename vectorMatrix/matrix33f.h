#ifndef MATRIX33F_H
#define MATRIX33F_H

#include "vec2f.h"
#include "vec3f.h"


class Matrix33f
{
private:
    float  m_matrix[9];

public:
    Matrix33f();
    Matrix33f( float val11, float val12, float val13,
               float val21, float val22, float val23,
               float val31, float val32, float val33);
    ~Matrix33f() {}


    float get(int x, int y) const;
    void set(int x, int y, float val);

    void set_Translation(const vec2f& v);
    void set_Translation(float dx, float dy);
    Matrix33f set_Rotation(float a);
    void set_Scaling(const vec2f& v);
    void set_Scaling(float sx, float sy);

    vec3f operator* (const vec3f& v);
    Matrix33f operator* (const Matrix33f& right);
    Matrix33f operator= (const Matrix33f& mat);

    Matrix33f translation(const vec2f& v);
    Matrix33f scaling(const vec2f& v);
    Matrix33f rotation(float);
    //Matrix33f inverse();

};

#endif // MATRIX33F_H
