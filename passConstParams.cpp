#include <iostream>
using namespace std;

template <class T>
T abc1(const T& a, const T& b, const T& c)
{
    a = 2 * b + c;                      // assigning a read-only variable 
    return a + b * c;
}

template <class T>
T abc2(const T& a, const T& b, const T& c)
{
    return a + b * c;
}

int main()
{
    double w = 2.8, x = 4.5, y = 3.6;
    double z;
    // z = abc1<double>(w,x,y);  // generates error
    z = abc2<double>(w,x,y);
    cout << z << endl;          // 19
}