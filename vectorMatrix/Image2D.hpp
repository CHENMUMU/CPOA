#ifndef IMAGE2D_HPP
#define IMAGE2D_HPP

#include "Image2D.h"

template<typename P>
Image2D<P>::Image2D(int width, int height)
{
    m_image = new P*[height];

    for(int i = 0; i < height; i++)
        m_image[i] = new P[width];

    m_width = width;
    m_height = height;
}


template<typename P>
Image2D<P>::Image2D(const Image2D<P>& source)
{
    int width = source.getWidth();
    int height = source.getHeight();
}

template<typename P>
void Image2D<P>::get(int x, int y)
{
    return m_image[x][y];
}

template<typename P>
int Image2D<P>::getWidth() const
{
     return m_width;
}

template<typename P>
int Image2D<P>::getHeight() const
{
     return m_height;
}

template<typename P>
void Image2D<P>::set(int x, int y, P val)
{
    m_image[x][y] = val;
}



#endif // IMAGE2D_HPP
