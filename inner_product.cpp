#include <iostream>

/**
 * 
 *     1. Algorithm INNNER-PRODUCT(A, B, n)
 *     2. {
 *     3.       Product_Sum := 0;
 *     4.       for i := 0 to n-1 do
 *     5.           Product_Sum := Product_Sum + (A[i] * B[i]);
 *     6.       return Product_Sum;
 *     7.
 *     8.} 
 * 
 *     Time complexity = O(n);
 *     Space complexity = O(n);
 */

template <typename T, size_t size>
T inner_product(T (&A)[size], T (&B)[size])
{
    T product_sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        product_sum += A[i] * B[i];
    }
    return product_sum;
}

int main()
{
    int a[3] = {1,2,3};
    std::cout << inner_product<int,sizeof(a)/sizeof(a[0])>(a,a) << std::endl; // 14
}