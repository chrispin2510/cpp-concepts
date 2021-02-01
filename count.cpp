#include <iostream>
/**
 *     1. Algorithm Count(A, n, value)
 *     2. // A is an array of size n in memory
 *     3. {
 *     4.       Count := 0;
 *     5.       for i := 0 to n-1 do
 *     6.       {
 *     7.           if (A[i] = value)
 *     8.               Count := Count + 1;
 *     9.       }
 *    10.       return Count;
 *    11. }
 * 
 *    Time Complexity = O(n);   Needed scanning whole array
 *    Space complexity = O(n);
 */

template <class T, size_t S>
size_t count(T (&arr)[S], T value)
{
    size_t count = 0;

    for (size_t i = 0; i < S; i++)
    {
        if (arr[i] == value)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {1,2,3,4,4,5};
    int value1 = 4, value2 = 5; 
    std::cout << count<int,sizeof(arr)/sizeof(arr[0])>(arr,value1) << std::endl;    // 2 
    std::cout << count<int,sizeof(arr)/sizeof(arr[0])>(arr,value2) << std::endl;    // 1
}