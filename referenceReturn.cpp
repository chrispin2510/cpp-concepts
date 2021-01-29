#include <iostream>
using namespace std;

template <class T>
T& mystery(int i, T& z)
{
    z = z + i;
    return z;      // z returned by reference
}                  // avoid returning value formal params or local Vars by ref!!

int main()
{
    double z = 0.0;
    
    for (int i = 1; i < 11; i++)
    {
        z = mystery(i, z);  // pass and return by reference
    }
    cout << z << endl;      // 55
}
