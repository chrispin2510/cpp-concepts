#include <iostream>
#include "lib0.hpp"

template <class T, size_t n>
void iota(T (&a)[n], T value)
{
    for (size_t i = 0; i < n; i++)
    {
        a[i] = i + value;
    }
}

int main()
{
    const int n = 3;
    int array[n] = {0};

    display<int, 3>(array); // 0,0,0 

    iota<int, 3>(array, 2);

    display<int, 3>(array); // 2, 3, 4

}