#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::bad_alloc;
using std::cerr;

int min(int x, int y)
{
    return (x > y ? y : x);
}

template <typename T>
void freeMem(T * &x)
{
    delete [] x;
    x = nullptr;
}

template <typename T>
void makeArray(T * &x, int numItems)
{
    x = new T [numItems];
}

template <typename T>
void arrayRealloc(T * &x, int oldLength, int newLength)
{
    T *newX = new T [newLength];
    int minLength = min(oldLength, newLength);
    // Copy old data
    for (int i = 0; i < minLength; i++) {
        newX[i] = x[i];
    }
    freeMem<int>(x);
    x = newX;
}

template <typename T>
void initArray(T * &x, int numItems)
{
    cout << "\nenter the elements:\n";
    for (int i = 0; i < numItems; i++) {
        cin >> x[i];
    }
}

template <typename T>
void printArray(T * &x, int numItems)
{
    cout << "\nArray:\n";
    for (int i = 0; i < numItems; i++) {
        if (i > 0 && i < numItems) { cout << ", "; }
        cout << x[i];
    }
    cout << endl;
}

int main()
{
    int *x = 0, *size, i = 0;

    try {
        makeArray<int>(size, 2);
    }
    catch (const bad_alloc& e) {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    cout << "\nenter size of the array: ";
    cin >> size[i];
    try {
        makeArray<int>(x, size[i]);
    }
    catch (bad_alloc) {
        cerr << "Memory allocation failure" << endl;
        exit(EXIT_FAILURE);
    }
    initArray<int>(x, size[i]);
    printArray<int>(x, size[i]);
    
    cout << "\nenter new size: ";
    cin >> size[++i];
    try { arrayRealloc<int>(x, size[i-1], size[i]); }
    catch (bad_alloc) {
        cerr << "Memory reallocation failure" << endl;
        exit(EXIT_FAILURE);
    }
    printArray<int>(x, size[i-1]);
    freeMem<int>(x);
}
