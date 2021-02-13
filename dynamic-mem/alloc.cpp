#include <iostream>

using std::cerr;
using std::endl;
using std::cin;
using std::bad_alloc;

int main()
{
    size_t n;
    cout << "How many items to process? ";
    cin >> n;
    float *x;
    try { x = new float[n]; }
    catch (const bad_alloc& e) {
        cerr << "Out of Memory" << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
