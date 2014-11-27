#include "matrix33f.h"
#include <cmath>

Matrix33f::Matrix33f()
{
    m_matrix[0] = 1.;
    m_matrix[4] = 1.;
    m_matrix[8] = 1.;

    m_matrix[1] = 0.;
    m_matrix[2] = 0.;
    m_matrix[3] = 0.;
    m_matrix[5] = 0.;
    m_matrix[6] = 0.;
    m_matrix[7] = 0.;
}


float Matrix33f::get(int x, int y) const
{
    return m_matrix[(3*x)+y];
}

void Matrix33f::set(int x, int y, float val)
{
    m_matrix[(3*x)+y] = val;
}

Matrix33f::Matrix33f( float val11, float val12, float val13,
           float val21, float val22, float val23,
           float val31, float val32, float val33)
{
    set(0,0,val11);
    set(0,1,val12);
    set(0,2,val13);
    set(1,0,val21);
    set(1,1,val22);
    set(1,2,val23);
    set(2,0,val31);
    set(2,1,val32);
    set(2,2,val33);
}


void Matrix33f :: set_Translation(const vec2f& v)
{
    set(0,2,v[0]);
    set(1,2,v[1]);

    set(0,0,1.);
    set(1,1,1.);
    set(2,2,1.);

    set(0,1,0.);
    set(1,0,0.);
    set(2,0,0.);
    set(2,1,0.);
}

void Matrix33f :: set_Translation(float dx, float dy)
{
    set(0,2,dx);
    set(1,2,dy);

    set(0,0,1.);
    set(1,1,1.);
    set(2,2,1.);

    set(0,1,0.);
    set(1,0,0.);
    set(2,0,0.);
    set(2,1,0.);

}

Matrix33f Matrix33f :: set_Rotation(float a)
{
    set(0,0,cos(a));
    set(1,1,cos(a));
    set(0,1,-sin(a));
    set(1,0,sin(a));

    set(2,2,1);

    set(0,2,0.);
    set(1,2,0.);
    set(2,0,0.);
    set(2,1,0.);
}

void Matrix33f :: set_Scaling(const vec2f& v)
{
    set(0,0,v[0]);
    set(1,1,v[1]);
    set(2,2,1.);

    set(0,2,0.);
    set(1,2,0.);
    set(2,0,0.);
    set(2,1,0.);
    set(0,1,0.);
    set(1,0,0.);
}
void Matrix33f :: set_Scaling(float sx, float sy)
{
    set(0,0,sx);
    set(1,1,sy);
    set(2,2,1.);

    set(0,2,0.);
    set(1,2,0.);
    set(2,0,0.);
    set(2,1,0.);
    set(0,1,0.);
    set(1,0,0.);
}

vec3f Matrix33f ::operator* (const vec3f& v)
{
    return vec3f( v[0]*m_matrix[0] + v[0]*m_matrix[3] + v[0]*m_matrix[6],
                  v[1]*m_matrix[1] + v[1]*m_matrix[4] + v[1]*m_matrix[7],
                  v[2]*m_matrix[2] + v[2]*m_matrix[5] + v[2]*m_matrix[8] );
}

Matrix33f Matrix33f :: operator= (const Matrix33f& mat)
{
    set(0, 0, mat.get(0, 0));
    set(0, 1, mat.get(0, 1));
    set(0, 2, mat.get(0, 2));

    set(1, 0, mat.get(1, 0));
    set(1, 1, mat.get(1, 1));
    set(1, 2, mat.get(1, 2));

    set(2, 0, mat.get(2, 0));
    set(2, 1, mat.get(2, 1));
    set(2, 2, mat.get(2, 2));

    return *this;
}

Matrix33f Matrix33f :: operator*(const Matrix33f& right)
{
    Matrix33f result;
    result.m_matrix[0] = m_matrix[0]*right.m_matrix[0]+m_matrix[1]*right.m_matrix[3]+m_matrix[2]*right.m_matrix[6];
    result.m_matrix[1] = m_matrix[0]*right.m_matrix[1]+m_matrix[1]*right.m_matrix[4]+m_matrix[2]*right.m_matrix[7];
    result.m_matrix[2] = m_matrix[0]*right.m_matrix[2]+m_matrix[1]*right.m_matrix[5]+m_matrix[2]*right.m_matrix[8];

    result.m_matrix[3] = m_matrix[3]*right.m_matrix[0]+m_matrix[4]*right.m_matrix[3]+m_matrix[5]*right.m_matrix[6];
    result.m_matrix[4] = m_matrix[3]*right.m_matrix[1]+m_matrix[4]*right.m_matrix[4]+m_matrix[5]*right.m_matrix[7];
    result.m_matrix[5] = m_matrix[3]*right.m_matrix[2]+m_matrix[4]*right.m_matrix[5]+m_matrix[5]*right.m_matrix[8];

    result.m_matrix[6] = m_matrix[6]*right.m_matrix[0]+m_matrix[7]*right.m_matrix[3]+m_matrix[8]*right.m_matrix[6];
    result.m_matrix[7] = m_matrix[6]*right.m_matrix[1]+m_matrix[7]*right.m_matrix[4]+m_matrix[8]*right.m_matrix[7];
    result.m_matrix[8] = m_matrix[6]*right.m_matrix[2]+m_matrix[7]*right.m_matrix[5]+m_matrix[8]*right.m_matrix[8];
    return result;

}

Matrix33f Matrix33f :: translation(const vec2f& v)
{
    Matrix33f m_result;
    m_result.m_matrix[0] = m_matrix[0];
    m_result.m_matrix[1] = m_matrix[1];
    m_result.m_matrix[2] = m_matrix[0]*v[0] + m_matrix[1]*v[1] + m_matrix[2];

    m_result.m_matrix[3] = m_matrix[3];
    m_result.m_matrix[4] = m_matrix[4];
    m_result.m_matrix[5] = m_matrix[3]*v[0] + m_matrix[4]*v[1] + m_matrix[5];

    m_result.m_matrix[6] = m_matrix[6];
    m_result.m_matrix[7] = m_matrix[7];
    m_result.m_matrix[8] = m_matrix[6]*v[0] + m_matrix[7]*v[1] + m_matrix[8];

    return m_result;

}

Matrix33f Matrix33f :: scaling(const vec2f& v)
{
    Matrix33f m_result;
    m_result.m_matrix[0] = m_matrix[0] * v[0];
    m_result.m_matrix[1] = m_matrix[1] * v[1];
    m_result.m_matrix[2] = m_matrix[2];

    m_result.m_matrix[3] = m_matrix[3] * v[0];
    m_result.m_matrix[4] = m_matrix[4] * v[1];
    m_result.m_matrix[5] = m_matrix[5];

    m_result.m_matrix[6] = m_matrix[6] * v[0];
    m_result.m_matrix[7] = m_matrix[7] * v[1];
    m_result.m_matrix[8] = m_matrix[8];

    return m_result;
}


Matrix33f Matrix33f :: rotation(float a)
{
    Matrix33f m_result;
    Matrix33f m_rot;
    m_result = m_rot*m_rot.set_Rotation(a);
    return m_result;
}

/*
Matrix33f::Matrix33f inverse()
{

}*/
