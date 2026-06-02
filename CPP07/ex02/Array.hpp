#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size; //hem fonksiyon adı hem değişken adı aynı olamaz bu sebeple değişken adını _size yaptım
    public:
        Array(): _array(NULL), _size(0){};
        Array(unsigned int n)
        {
            _array = new T[n]();
            _size = n;
        }

        Array(const Array& other)
        {
            _size = other.size(); //other._size yapamayız çünkü private, eğer farklı türden bir referans verseydik o zaman private olduğu için çalışmazdı
            _array = new T[_size]();
            unsigned int i = 0;
            while(i < _size)
            {
                _array[i] = other._array[i];
                i++;
            }
        }
        Array& operator=(const Array& other)
        {
            if(this != &other)
            {
                delete[] _array;
                _size = other.size();
                if(_size > 0)
                {
                    _array = new T[_size]();
                    unsigned int i = 0;
                    while(i < _size)
                    {
                        _array[i] = other._array[i];
                        i++;
                    }
                }
                else
                    _array = NULL;  
            }    
            return *this;
            
        }

        T& operator[](unsigned int index)
        {
                if(index >= _size)
                    throw std::out_of_range("Index out of range");
                return _array[index];
        }

        const T& operator[](unsigned int index) const
        {
                if(index >= _size)
                    throw std::out_of_range("Index out of range");
                return _array[index];
        }

        ~Array()
        {
            delete[] _array;
        }
        
        unsigned int size() const
        {
            return _size;
        }
};

#endif