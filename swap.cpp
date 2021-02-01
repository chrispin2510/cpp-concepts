// Implements the swap() procedure using concept of pass-by-reference

#include <iostream>

template <class T>
void swap(T& value1, T& value2)
{
    T temp = value1;
    value1 = value2;
    value2 = temp;
}

int main()
{
    int x = 10, y = 20;
    std::cout << "Before swapping: x = " << x << ", y = " << y << std::endl;
    swap(x,y);
    std::cout << "After swapping: x = " << x << ", y = " << y << std::endl;

    // Program output
    /**
     *   Before swapping: x = 10, y = 20
     *   After swapping: x = 20, y = 10
     */
}