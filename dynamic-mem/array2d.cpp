#include <iostream>

using std::cout; using std::cerr;
using std::cin;  using std::bad_alloc;
using std::endl;

template <class T>
void makeArray(T * &x, int numItems)
{
    x = new T [numItems];
}

template <class T>
void make2dArray(T ** &x, int numRows, int * rowSize)
{
    x = new T * [numRows];
    for (int i = 0; i < numRows; i++) {
        x[i] = new T [rowSize[i]];
    }
}

template <class T>
void init2dArray(T ** &x, int numRows, int * rowSize)
{
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowSize[i]; j++) {
            cin >> x[i][j];
        }
    }
}

template <class T>
void delete2dArray(T ** &x, int numRows)
{
    for (int i = 0; i < numRows; i++) {
        delete [] x[i];
    }
    delete [] x;
    x = nullptr;
}

template <class T>
void display2dArray(T ** &x, int numRows, int * rowSize)
{
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowSize[i]; j++) {
            if (j > 0 && j < rowSize[i]) { cout << ", "; }
            cout << x[i][j]; 
        }
        cout << endl;
    }
}

int main() 
{
    int **x = nullptr;
    int *rowSize = nullptr;
    int numRows;

    cout << "\nenter number of rows: ";
    cin >> numRows;

    // Create matrix
    try {
        makeArray<int>(rowSize, numRows);
    }
    catch (bad_alloc) {
        cerr << "Caught memory error" << endl; 
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < numRows; i++) {
        cout << "enter size of row " << (i + 1) << " : ";
        cin >> rowSize[i]; 
    }
    try {
        make2dArray<int>(x, numRows, rowSize);
    }
    catch (bad_alloc) {
        cerr << "Could not create matrix." << endl;
        exit(EXIT_FAILURE);
    }
    init2dArray<int>(x, numRows, rowSize);
    display2dArray<int>(x, numRows, rowSize);
    delete2dArray<int>(x, numRows);
    return 0;
}
