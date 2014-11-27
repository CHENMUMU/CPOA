#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <iostream>
#include "vecteur.h"
#include "array.h"

// Operator
template< typename T,unsigned int N>
vecteur <T,N> vecteur <T,N>::operator+ (const vecteur <T,N>& vec)
{
    vecteur <T,N> result = new vecteur <T,N>(vec.size());
    if (this->size() == vec.size()) {
        for (int i = 0; i < vec.size(); ++i) {
            result[i] = this -> m_data[i] + vec[i];
        }
    }
    return result;
}

template< typename T,unsigned int N>
vecteur <T,N> vecteur <T,N>::operator+= (const vecteur <T,N>& vec)
{
    
    if (this->size() == vec.size()) {
        for (int i = 0; i < vec.size(); ++i) {
            this -> m_data[i] = this -> m_data[i] + vec[i];
        }
    }
    return this;
}

template<typename T,unsigned int N>
vecteur <T,N> vecteur <T,N>::operator- (const vecteur <T,N>& vec)
{
    vecteur <T,N> result = new vecteur <T,N>(vec.size());
    if (this->size() == vec.size()) {
        for (int i = 0; i < vec.size(); ++i) {
            result[i] = this -> m_data[i] - vec[i];
        }
    }
    return result;
}

template<typename T,unsigned int N>
vecteur <T,N> vecteur <T,N>::operator-= (const vecteur <T,N>& vec)
{
    
    if (this->size() == vec.size()) {
        for (int i = 0; i < vec.size(); ++i) {
            this -> m_data[i] = this -> m_data[i] - vec[i];
        }
    }
    return this;
}


template<typename T,unsigned int N>
vecteur <T,N> vecteur <T,N>::operator* (const T& scalaire)
{
    vecteur <T,N> result = new vecteur <T,N>(this ->size());
    
    for (int i = 0; i < this -> size(); ++i) {
            result[i] = this -> m_data[i] * scalaire;
        }
    
    return result;
}

template< typename T,unsigned int N>
vecteur <T,N> vecteur <T,N>::operator*= (const T& scalaire)
{
    for (int i = 0; i < this -> size(); ++i) {
        this -> m_data[i] = this -> m_data[i] * scalaire;
    }
    
    return this;
}

template< typename T,unsigned int N>
vecteur <T,N> vecteur <T,N>::operator/ (const T& scalaire)
{
    vecteur <T,N> result = new vecteur <T,N>(this -> size());
    
    for (int i = 0; i < this -> size(); ++i) {
        result[i] = this -> m_data[i] / scalaire;
    }
    
    return result;
}

template< typename T,unsigned int N>
vecteur <T,N> vecteur <T,N>::operator/= (const T& scalaire)
{
    for (int i = 0; i < this -> size(); ++i) {
        this -> m_data[i] = this -> m_data[i] / scalaire;
    }
    
    return this;
}
#endif // VECTEUR_HPP
