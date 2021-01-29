#include <iostream>
using namespace std;

template <class T>
T abc(T a, T b, T c)
{
    return a + b * c;
}

int main()
{
    double x = 3.9;
    double y = 4.7;
    int p = 3;
    int q = 4;
    int t;
    double s;
    t = abc<int>(2,p,q);        // invoke as int abc(int,int,int)
    s = abc<double>(2,x,y);     // invoke as double abc(double,double,double)

    cout << t << endl;          // 14 
    cout << s << endl;          // 20.33 
}