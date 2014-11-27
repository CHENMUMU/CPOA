#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include "array.h"

template <typename T,unsigned int N>
class vecteur : public Array<T,N>
{
public:
    
    // Constructor
    vecteur(){}
    vecteur(int size):Array <T,N>(size){}

    // Constructor de copie
    vecteur(const Array<T,N>& array):Array<T,N>(array){}
    // Destructor
    ~vecteur(){}
    
    // Operator
    vecteur <T,N> operator+ (const vecteur <T,N>& vec);
    vecteur <T,N> operator+= (const vecteur <T,N>& vec);
    
    vecteur <T,N> operator- (const vecteur <T,N>& vec);
    vecteur <T,N> operator-=( const vecteur <T,N>& vec);
    
    vecteur <T,N> operator* (const T& scalaire);
    vecteur <T,N> operator*= (const T& scalaire);
    
    vecteur <T,N> operator/ (const T& scalaire);
    vecteur <T,N> operator/= (const T& scalaire);

    
};

#endif // VECTEUR_H
