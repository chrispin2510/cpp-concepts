#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

static int min(int x, int y)
{
    return (x > y ? y : x);
}

template <typename T>
static void freeMem(T * &x)
{
    delete [] x;
    x = nullptr;
}

template <typename T>
static void makeArray(T * &x, int numItems)
{
    x = new T [numItems];
}

template <typename T>
extern void arrayRealloc(T * &x, int oldLength, int newLength)
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
extern void initArray(T * &x, int numItems)
{
    cout << "\nenter the elements:\n";
    for (int i = 0; i < numItems; i++) {
        cin >> x[i];
    }
}

template <typename T>
extern void printArray(T * &x, int numItems)
{
    cout << "\nArray:\n";
    for (int i = 0; i < numItems; i++) {
        if (i > 0 && i < numItems) { cout << ", "; }
        cout << x[i];
    }
    cout << endl;
}

template <class T>
static void make2dArray(T ** &x, int numRows, int * rowSize)
{
    x = new T * [numRows];
    for (int i = 0; i < numRows; i++) {
        x[i] = new T [rowSize[i]];
    }
}

template <class T>
extern void init2dArray(T ** &x, int numRows, int * rowSize)
{
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowSize[i]; j++) {
            cin >> x[i][j];
        }
    }
}

template <class T>
extern void delete2dArray(T ** &x, int numRows)
{
    for (int i = 0; i < numRows; i++) {
        delete [] x[i];
    }
    delete [] x;
    x = nullptr;
}

template <class T>
extern void print2dArray(T ** &x, int numRows, int * rowSize)
{
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowSize[i]; j++) {
            if (j > 0 && j < rowSize[i]) { cout << ", "; }
            cout << x[i][j]; 
        }
        cout << endl;
    }
}

template <typename T>
extern void changeLength2D(T ** &x, int oldNumRows, int * oldRowSize, int newNumRows, int * newRowSize)
{
    int minNumRows = min(oldNumRows, newNumRows);
    for (int i = 0; i < minNumRows; i++) {
        arrayRealloc(x[i], oldRowSize[i], newRowSize[i]);
    }
}


#endif /* ARRAY_H */
