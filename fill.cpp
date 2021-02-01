#include <iostream>

template <class T, size_t size>
void fill_arr(T (&)arr[size], T value)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = value;
    }
}

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

int main()
{
    const int size = 10;
    int arr[size];

    // fill_arr with 0s
    fill_arr<int, size>(arr, 0);

    display<int, sizeof(arr)/sizeof(arr[0])>(arr);

    // fill_arr with 1s
    fill_arr<int, sizeof(arr)/sizeof(arr[0])>(arr, 1);

    display<int, sizeof(arr)/sizeof(arr[0])>(arr);
}