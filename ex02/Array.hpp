#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array(): _array(NULL), _size(0){};
        Array(unsigned int n)
        {
            _array = new T[n]();
            _size = n;
        }

        Array(const Array& other)
        {
            _size = other.size();
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
                _array = new T[_size]();
                unsigned int i = 0;
                while(i < _size)
                {
                    _array[i] = other._array[i];
                    i++;
                }
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