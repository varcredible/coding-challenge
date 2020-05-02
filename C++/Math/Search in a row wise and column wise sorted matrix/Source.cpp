#include <iostream>

int searchXInTheMatrix(const int _MAT[4][4], const int _N, const int _X);

int main()
{
    int mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50} };

    const int N = sizeof(mat) / sizeof(mat[0]);
    int x = 29;

    searchXInTheMatrix(mat, N, x); // -> Output: Element at (2,1) is 29

    return 0;
}

int searchXInTheMatrix(const int _MAT[4][4], const int _N, const int _X)
{
    for (int row = 0; row < _N; row++)
    {
        for (int column = 0; column < _N; column++)
        {
            if (_X == _MAT[row][column])
            {
                printf("Element at (%d,%d) is %d", row, column, _X);
                return 0;
            }
        }
    }

    printf("Element not found");
    return 0;
}
