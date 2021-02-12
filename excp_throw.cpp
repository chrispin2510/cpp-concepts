#include <iostream>

using namespace std;

int abc(int a, int b, int c)
{
    return a + b * c + b / c;       
}

int main(int argc, char** argv) 
{
    try { cout << abc(2,4,0) << endl; }
    catch (const exception& e) {
        cout << "Exception raised: " << e.what() << endl;
    }
    return 0;
}