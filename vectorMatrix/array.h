#ifndef ARRAY_H
#define ARRAY_H
#include <string>

template <typename T,unsigned int N>
class Array
{

private:
    T m_data[N];
    int nb_element;
    int m_size;


public:
    // Constructor
    Array();
    Array(int size);
    
    // Copie le constructor
    Array(const Array<T,N>& vec);
    
    void set(unsigned int i, const T& val);
    void fill(const T& t);
    int getSize() const;



    // Destructor
    ~Array();
    
    // Surcharger l'operator
    T & operator[](int i);
    T  operator[](int i) const;
   
    Array<T,N> operator = (const Array<T,N>& array);
    
    // Comparaison entre deux array
    bool operator == (const Array<T,N>& array) const;
    bool operator <= (const Array<T,N>& array) const;
    bool operator >= (const Array<T,N>& array) const;
    
    // Echanger deux array
    void swap(Array<T,N>& array);

};



#endif // ARRAY_H
