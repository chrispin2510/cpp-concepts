#include <iostream>
#include "array.h"

using std::cout;
using std::cerr;
using std::endl;
using std::bad_alloc;

int main()
{
    int **x;
    int *numRows, i = 0;
    int **rowSize, *numRowSizes;
    
    try {
        makeArray<int>(numRows, 2);
        make2dArray<int>(rowSize, 2, );
    }
    catch (const bad_alloc& e) {
        cerr << "Caught " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    cout << "\nenter number of rows: ";
    cin >> numRows[i];
    for (int j = 0; j < numRows[i]; j++) {
        cout << "\nenter size of column " << (j + 1) << " : ";
        cin >> rowSize[i][j];
    }
    try {
        make2dArray<int>(x, numRows[i], rowSize[i]);
    }
    catch (const bad_alloc& e) {
        cerr << "Caught " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    init2dArray<int>(x, numRows[i], rowSize[i]);
    print2dArray(x, numRows[i], rowSize[i]);
    return 0;
}
