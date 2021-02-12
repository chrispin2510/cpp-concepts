#include <iostream>

using namespace std;

int abc(int a, int b, int c)
{
    return a + b * c + b / c;       // potential divide by 0 error when c = 0!
}

int main(int argc, char** argv) 
{
    int a = 2, b = 1, c = 0;
    cout << abc(a,b,c) << endl; // floating point excecption
}