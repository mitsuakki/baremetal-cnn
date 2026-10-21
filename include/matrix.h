#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct Matrix
{
    size_t rows;
    size_t columns;
    double *data;
} Matrix;

#define AT(matrix, row, column) ((matrix)->data[(row) * (matrix)->columns + (column)])

Matrix *matrix_new(size_t rows, size_t cols);
void    matrix_free(Matrix *m);
void    matrix_print(const Matrix *m);

/* "Valid" 2D convolution, stride 1, no padding.
 * Returns NULL on allocation failure or if kernel > input. */
Matrix *matrix_conv2d(const Matrix *input, const Matrix *kernel);

#endif // MATRIX_H
