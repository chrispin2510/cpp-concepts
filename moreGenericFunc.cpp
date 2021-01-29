#include <iostream>
using namespace std;

template <class Ta, class Tb, class Tc>
Ta abc(const Ta& a, const Tb& b, const Tc& c)
{
    return a + b * c;
}

int main()
{
    double x = 4.7;
    float y = 5.5f;
    int w = 2;
    double z = abc<double,float,int>(x,y,w);

    cout << z << endl;      // 15.7 
}