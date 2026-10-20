#include "../include/matrix.h"


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
