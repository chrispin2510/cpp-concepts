#include <iostream>
using namespace std;

int abc(int a, int b, int c)    // formal paramaters a,b,c
{
    return a + b * c;
}

int main()
{
    double x = 3.8;
    double y = 4.8;
    double z = abc(2,x,y);     // copying actual parameters 2,x,y
    cout << z << endl;         // ans = 14; copied and type-casted! 
}