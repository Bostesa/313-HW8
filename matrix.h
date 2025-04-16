#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Matrix structure
typedef struct {
    double** data;
    size_t rows;
    size_t cols;
} Matrix;

// Matrix creation and destruction functions
Matrix* matrix_create(size_t rows, size_t cols);
Matrix* matrix_create_from_array(double* arr, size_t rows, size_t cols);
void matrix_destroy(Matrix* mat);

// Element access functions
double matrix_get(const Matrix* mat, size_t row, size_t col);
void matrix_set(Matrix* mat, size_t row, size_t col, double value);

// Matrix operations
Matrix* matrix_add(const Matrix* mat1, const Matrix* mat2);
Matrix* matrix_subtract(const Matrix* mat1, const Matrix* mat2);
Matrix* matrix_multiply(const Matrix* mat1, const Matrix* mat2);
Matrix* matrix_scalar_multiply(const Matrix* mat, double scalar);
Matrix* matrix_transpose(const Matrix* mat);

// Utility functions
void matrix_print(const Matrix* mat);
bool matrix_equals(const Matrix* mat1, const Matrix* mat2, double epsilon);

#endif // MATRIX_H