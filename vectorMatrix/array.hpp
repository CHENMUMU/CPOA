#ifndef ARRAT_HPP
#define ARRAT_HPP

#include <iostream>
#include "array.h"

using namespace std;


//  Constructeur
template <typename T, unsigned int N>
Array<T,N>::Array()
{
}

template <typename T, unsigned int N>
Array<T,N>::Array(int size):m_size(size),m_data(NULL)
{
    nb_element = 0;
    m_data = new T[size];
    std::cout << "Le Size est:%d.\n" << m_size << std::endl;
}


//Copie le constructor
template <typename T, unsigned int N>
Array<T,N> :: Array(const Array<T,N>& vec)
{
    this -> m_size = vec.m_size;
    this -> nb_element = vec.nb_element;
    for (int i = 0; i < vec.m_size; ++i) {
        this -> m_data[i] = vec.m_data[i];
    }
}

template <typename T, unsigned int N>
void Array<T,N>::set(unsigned int i, const T& val)
{
    this -> m_data[i] = val;
}



template <typename T, unsigned int N>
void Array<T,N>::fill(const T& t)
{
    for(unsigned int i = 0; i<N; i++)
        set(i,t);
}


// Get le size
template <typename T, unsigned int N>
int Array<T,N>::getSize() const
{
    return m_size;
    std::cout << "Size est : %d.\n" << m_size << std::endl;
}

// Destructor
template <typename T, unsigned int N>
Array<T,N>::~Array()
{
}

//Operator
template <typename T, unsigned int N>
T& Array<T,N>::operator[](int i)
{
    return m_data[i];
}

template <typename T, unsigned int N>
T  Array <T,N>::operator[](int i) const
{
    return m_data[i];
}

template <typename T, unsigned int N>
Array<T,N> Array<T,N>::operator=(const Array<T,N>& array)
{
    int size = array.getSize();
    
    for (int i = 0; i < size; ++i) {
        this -> m_data[i] = array[i];
    }
    return this;
    
}


// Comparaison entre deux array!
template <typename T, unsigned int N>
bool Array<T,N>::operator==(const Array<T,N>& array) const
{
    assert(getSize()==array.getSize());
    
    
    for (int i = 0; i < array.getSize(); ++i) {
        if (this -> m_data[i] != array[i]) {
            return false;
        }
    }
    return true;
   
}

template <typename T, unsigned int N>
bool Array<T,N>::operator <= (const Array<T,N>& array) const
{
    assert(this -> nb_element == array.nb_element);
    
    for (int i = 0; i < nb_element; ++i) {
        if (this -> m_data[i] > array[i]) {
            return false;
        }
    }
    return true ;
}

template <typename T, unsigned int N>
bool Array<T,N>::operator >= (const Array<T,N>& array) const
{
    assert(this -> nb_element == array.nb_element);
    
    for (int i = 0; i < nb_element; ++i) {
        if (this -> m_data[i] < array[i]) {
            return false;
        }
    }
    return true ;
}

// Echanger deux array
template <typename T, unsigned int N>
void Array<T,N>::swap(Array<T,N>& array)
{
    assert(this -> nb_element == array.nb_element);
    
    for (int i = 0; i < this -> m_size; ++i) {
        T temp = this -> m_data[i];
        this -> m_data[i] = array[i];
        array[i] = temp;
    }
}





#endif // ARRAT_HPP
