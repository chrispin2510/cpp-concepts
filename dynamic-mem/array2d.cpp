#include <iostream>

using std::cout; using std::cerr;
using std::cin;  using std::bad_alloc;
using std::endl;

template <class T>
void make2dArray(T ** &x, int numOfRows, int numOfCols)
{
    x = new T * [numOfRows];
    for (int i = 0; i < numOfRows; i++) {
        x[i] = new T [numOfCols];
    }
}

template <class T>
void init2dArray(T ** &x, int numOfRows, int numOfCols)
{
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            cin >> x[i][j];
        }
    }
}

template <class T>
void delete2dArray(T ** &x, int numOfRows)
{
    for (int i = 0; i < numOfRows; i++) {
        delete [] x[i];
    }
    delete [] x;
    x = nullptr;
}

template <class T>
void display2dArray(T ** &x, int numOfRows, int numOfCols)
{
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            if (j > 0 && j < numOfCols) { cout << ", "; }
            cout << x[i][j]; 
        }
        cout << endl;
    }
}

int main() 
{
    int **x;
    int numOfRows, numOfCols;

    cout << "\nenter number of rows: ";
    cin >> numOfRows;
    cout << "\nenter number of cols: ";
    cin >> numOfCols;

    try {
        make2dArray(x, numOfRows, numOfCols);
    }
    catch (bad_alloc) {
        cerr << "Matrix could not be created" << endl;
        exit(EXIT_FAILURE);
    }
    init2dArray(x, numOfRows, numOfCols);
    display2dArray(x, numOfRows, numOfCols);
    delete2dArray(x, numOfRows);
    return 0;
}
