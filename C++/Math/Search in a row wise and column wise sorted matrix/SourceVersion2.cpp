// with using boolean + pointers //

#include <iostream>

bool isThereXInTheMatrix(const int _MAT[4][4], const int _N, const int _X, int* _row, int* _column)
{
    for (size_t row = 0; row < _N; row++)
    {
        for (size_t column = 0; column < _N; column++)
        {
            if (_X == _MAT[row][column])
            {
                *_row = row;
                *_column = column;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50} };

    const int N = sizeof(mat) / sizeof(mat[0]);
    int x = 29, row = 0, column = 0;
    int* ptr_row = &row, * ptr_column = &column;

    isThereXInTheMatrix(mat, N, x, ptr_row, ptr_column) ?  
        printf("Element at (%d,%d) is %d", row, column, x) :       // -> Output: Element at (2,1) is 29
        printf("Element not found"); 

    return 0;
}
