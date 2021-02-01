#include <iostream>
#include <iomanip>

template <class T, size_t N>
bool is_sorted(T (&A)[N])
{
    bool flag = true;

    if (A[1] > A[0])
    {
        for (size_t i = 1; i < N; i++)
        {
            if (A[i] < A[i-1])
            {
                flag = false;
            }
        }
    }   
    else 
    {
        for (size_t i = 1; i < N; i++)
        {
            if (A[i] > A[i-1])
            {
                flag = false;
            }
        }
    }
    return flag;
}

int main()
{
    int sorted_arr[] = {1,2,3,3,4,4,5};
    int unsorted_arr[] = {1,2,3,2,4,4,2};

    std::cout << std::boolalpha << is_sorted<int, sizeof(sorted_arr)/sizeof(sorted_arr[0])>(sorted_arr) << std::endl;   // true
    std::cout << std::boolalpha << is_sorted<int, sizeof(unsorted_arr)/sizeof(unsorted_arr[0])>(unsorted_arr) << std::endl; // false
}