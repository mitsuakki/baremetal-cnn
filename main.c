#include <stdio.h>
#include "include/matrix.h"


int main(void)
{
    Matrix *image  = matrix_new(5, 5);
    Matrix *kernel = matrix_new(3, 3);

    for (size_t i = 0; i < image->rows * image->columns; i++)
        image->data[i] = (double)(i + 1);

    double kdata[9] = { -1, 0, 1,
                        -2, 0, 2,
                        -1, 0, 1 };

    for (size_t i = 0;i < 9; i++)
        kernel->data[i] = kdata[i];

    matrix_print(image);

    matrix_free(image);
    matrix_free(kernel);
}
