#include <iostream>

using namespace std;

int abc(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        throw "All parameters should be > 0";
    return a + b * c + b / c;       
}

int main(int argc, char** argv) 
{
    try { cout << abc(2,0,3); }
    catch (char* e) {
        cout << "Exception: " << e << endl;
    }
    return 0;
}