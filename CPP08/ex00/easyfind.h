#ifndef EASYFIND_H
#define EASYFIND_H

#include <exception>
#include <algorithm>

class NotFoundException : public std::exception {
    public:
        const char* what() const throw()
        {
            return "Value not found in the container.";
        }
};


template <typename T>
typename T::iterator easyfind(T& container, int value) { //typename anahtar kelimesini orada kullanmamızın sebebi, C++ derleyicisinin T::iterator ifadesinin bir tür (type) mi yoksa bir değişken/üye (member) mi olduğunu önceden kestirememesidir. 
    typename T::iterator it = std::find(container.begin(), container.end(), value); //value bulunamazsa end() iterator'ını döndürür, bulunursa o değerin (fonksiyondaki) iterator'ını döndürür
    if (it != container.end())
        return it;
    throw NotFoundException();
}

#endif