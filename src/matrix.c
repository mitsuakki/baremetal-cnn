#include "../include/matrix.h"
#include <stddef.h>


Matrix *matrix_new(size_t rows, size_t colums)
{
    Matrix *m = malloc(sizeof *m);
    if (!m)
        return NULL;

    m->rows = rows;
    m->columns = colums;

    m->data = calloc(rows * colums, sizeof(*m->data));
    if (!m->data)
    {
        free(m);
        return NULL;
    }

    return m;
}

void matrix_free(Matrix *m) {
    if (!m) return;

    free(m->data);
    free(m);
}

void matrix_print(const Matrix *m)
{
    for (size_t i = 0; i < m->rows; i++)
    {
        for (size_t j = 0; j < m->columns; j++)
            printf("%8.2f", AT(m, i, j));
        putchar('\n');
    }
}

Matrix *matrix_conv2d(const Matrix *input, const Matrix *kernel)
{
    if (kernel->rows > input->rows || kernel->columns > input->columns)
        return NULL;

    size_t oh = input->rows - kernel->rows + 1;
    size_t ow = input->columns - kernel->columns + 1;
    Matrix *out = matrix_new(oh, ow);
    if (!out)
        return NULL;

    for (size_t i = 0; i < oh; i++)
    {
        for (size_t j = 0; j < ow; j++)
        {
            double sum = 0.0;
            for (size_t u = 0; u < kernel->rows; u++)
            {
                for (size_t v = 0; v < kernel->columns; v++)
                {
                    double kv = AT(kernel, u, v);
                    sum += AT(input, i + u, j + v) * kv;
                }
            }
            AT(out, i, j) = sum;
        }
    }

    return out;
}
