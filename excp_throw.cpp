#include <iostream>

using namespace std;

int abc(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        throw "All parameters should be > 0";
    return a + b * c + b / c;       // potential divide by 0 error when c = 0!
}

int main(int argc, char** argv) 
{
    int a = 2, b = 1, c = 0;
    cout << abc(a,b,c) << endl; // instance of 'char const*' will be thrown
}