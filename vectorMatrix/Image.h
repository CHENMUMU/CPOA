#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include "array.h"

template<typename P,int Dimension>
class Image
{
protected:
    Array<unsigned,Dimension> size;
    P* m_image;

public:
    Image();
    Image(const Array<unsigned,Dimension> dim);
    ~Image();

    P get(Array<unsigned, Dimension>const coord);

    void copy(const Image<P,Dimension>& source);


};

#endif // IMAGE_H
