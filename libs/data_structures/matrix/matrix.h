//
// Created by lizka on 14.02.2022.
//

#ifndef MAIN_C_MATRIX_H
#define MAIN_C_MATRIX_H
typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

#endif //MAIN_C_MATRIX_H
