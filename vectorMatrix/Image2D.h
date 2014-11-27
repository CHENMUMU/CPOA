#ifndef IMAGE2D_H
#define IMAGE2D_H

template<typename P>
class Image2D
{
protected:

    P** m_image;
    int m_width;
    int m_height;

public:
    Image2D(int width, int height);
    Image2D(const Image2D<P>& source);
    ~Image2D();

    void get(int x, int y);
    int getWidth() const;
    int getHeight() const;

    void set(int x, int y, P val);

};

#endif // IMAGE2D_H
