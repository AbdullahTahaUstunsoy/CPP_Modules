#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.number = 42;
    data.text = "Serialization text";

    std::cout << "Original Address:" << &data << std::endl;

    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized Value: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Address: " << deserialized << std::endl;

    if (&data == deserialized)
    {
        std::cout << "&data: " << &data << " | " << "deserialized: " << deserialized << std::endl;
        std::cout << "Deserialization successful, addresses match!" << std::endl;
    }
    else
        std::cout << "Deserialization failed, addresses do not match." << std::endl;
    return (0);
}