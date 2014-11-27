#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "Image.h"

template<typename P,int Dimension>
Image<P,Dimension>::Image()
{
}

template<typename P,int Dimension>
Image<P,Dimension>::Image(const Array<unsigned,Dimension> sz)
{
    int s = 1;
    for(int i = 0; i< Dimension; ++i)
    {
        s = s * sz[i];
    }

    size = sz;
    m_image = new P[s];
}

template<typename P,int Dimension>
Image<P,Dimension>::~Image()
{
    delete m_image;
}

template<typename P,int Dimension>
P Image<P,Dimension>::get(Array<unsigned, Dimension>const coord)
{
    int pixel = 0;
    for(int i = 0; i<=Dimension; ++i)
    {
        pixel += i*coord[i];
    }
    return m_image[pixel];
}



#endif // IMAGE_HPP
