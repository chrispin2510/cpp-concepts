#ifndef LIB0_H
#define LIB0_H

#include <cstdlib>

template <class T, size_t size>
void display(T (&arr)[size])
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i < size - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

#endif /* LIB0_H */