#include <iostream>
using namespace std;

int abc(int a, int b, int c)
{
    return a + b * c;
}

double abc(double a, double b, double c)
{
    return a + b * c;
}

int abc(int a, int b)
{
    return a + b;
}

//int abc(double a, double b, double c)     // conflict func `abc` on line 9
//{
//    return a + b * c;
//}

int main()
{
    // abc() has been overloaded three(3) times
    double x = 5.6, y = 4.4, w = 4.5;
    int p = 1, q = 5, r;
    double z = abc(x,y,w);  // abc(double,double,double) used
    cout << z << endl;      // 25.4
    r = abc(p,q);           // abc(int,int) used 
    cout << r << endl;      // 6 
    r = abc(2,p,q);         // abc(int,int,int) used 
    cout << r << endl;      // 7
}