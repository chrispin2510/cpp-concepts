#include <iostream>
using namespace std;

template <class T>
T abc(T& a, T& b, T& c)       // reference actual parameters
{
    return a + b * c;
} 

int main()
{
    double w = 2, x = 3.8, y = 4.9;
    double z = abc<double>(w,x,y);  // no copying of actual paramters! 
    cout << z << endl;              // 20.62
}