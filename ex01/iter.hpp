#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <typename T, typename F>
void iter(T *array, size_t const length, F f)
{
    if(!array || length == 0)
        return;
    for(size_t i = 0; i < length; i++)
        f(array[i]);
}


#endif