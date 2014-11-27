#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H


#include "Image2D.h"
#include "matrix33f.h"
#include "Image2Grey.hpp"

class Image2Grey:public Image2D<char>
{
public:
    Image2Grey(int x, int y) : Image2D<char>(x,y) {}
    Image2Grey(const char& name);


}

#endif // IMAGE2GREY_H
