#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Matrix creation and destruction functions
Matrix* matrix_create(size_t rows, size_t cols) {
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    if (!mat) {
        fprintf(stderr, "Memory allocation failed for matrix\n");
        return NULL;
    }
    
    mat->rows = rows;
    mat->cols = cols;
    
    // Allocating memory for rows
    mat->data = (double**)malloc(rows * sizeof(double*));
    if (!mat->data) {
        fprintf(stderr, "Memory allocation failed for matrix rows\n");
        free(mat);
        return NULL;
    }
    
    // Allocating memory for columns and initializing to zero
    for (size_t i = 0; i < rows; i++) {
        mat->data[i] = (double*)calloc(cols, sizeof(double));
        if (!mat->data[i]) {
            fprintf(stderr, "Memory allocation failed for matrix columns\n");
            // Freeing previously allocated memory
            for (size_t j = 0; j < i; j++) {
                free(mat->data[j]);
            }
            free(mat->data);
            free(mat);
            return NULL;
        }
    }
    
    return mat;
}

Matrix* matrix_create_from_array(double* arr, size_t rows, size_t cols) {
    Matrix* mat = matrix_create(rows, cols);
    if (!mat) return NULL;
    
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            mat->data[i][j] = arr[i * cols + j];
        }
    }
    
    return mat;
}

void matrix_destroy(Matrix* mat) {
    if (mat) {
        if (mat->data) {
            for (size_t i = 0; i < mat->rows; i++) {
                free(mat->data[i]);
            }
            free(mat->data);
        }
        free(mat);
    }
}

// Element access functions
double matrix_get(const Matrix* mat, size_t row, size_t col) {
    if (row >= mat->rows || col >= mat->cols) {
        fprintf(stderr, "Matrix index out of bounds\n");
        return 0.0;
    }
    return mat->data[row][col];
}

void matrix_set(Matrix* mat, size_t row, size_t col, double value) {
    if (row >= mat->rows || col >= mat->cols) {
        fprintf(stderr, "Matrix index out of bounds\n");
        return;
    }
    mat->data[row][col] = value;
}

// Matrix operations
Matrix* matrix_add(const Matrix* mat1, const Matrix* mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        fprintf(stderr, "Matrix dimensions do not match for addition\n");
        return NULL;
    }
    
    Matrix* result = matrix_create(mat1->rows, mat1->cols);
    if (!result) return NULL;
    
    for (size_t i = 0; i < mat1->rows; i++) {
        for (size_t j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    
    return result;
}

Matrix* matrix_subtract(const Matrix* mat1, const Matrix* mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        fprintf(stderr, "Matrix dimensions do not match for subtraction\n");
        return NULL;
    }
    
    Matrix* result = matrix_create(mat1->rows, mat1->cols);
    if (!result) return NULL;
    
    for (size_t i = 0; i < mat1->rows; i++) {
        for (size_t j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
        }
    }
    
    return result;
}

Matrix* matrix_multiply(const Matrix* mat1, const Matrix* mat2) {
    if (mat1->cols != mat2->rows) {
        fprintf(stderr, "Matrix dimensions are not compatible for multiplication\n");
        return NULL;
    }
    
    Matrix* result = matrix_create(mat1->rows, mat2->cols);
    if (!result) return NULL;
    
    for (size_t i = 0; i < mat1->rows; i++) {
        for (size_t j = 0; j < mat2->cols; j++) {
            double sum = 0.0;
            for (size_t k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    
    return result;
}

Matrix* matrix_scalar_multiply(const Matrix* mat, double scalar) {
    Matrix* result = matrix_create(mat->rows, mat->cols);
    if (!result) return NULL;
    
    for (size_t i = 0; i < mat->rows; i++) {
        for (size_t j = 0; j < mat->cols; j++) {
            result->data[i][j] = mat->data[i][j] * scalar;
        }
    }
    
    return result;
}

Matrix* matrix_transpose(const Matrix* mat) {
    Matrix* result = matrix_create(mat->cols, mat->rows);
    if (!result) return NULL;
    
    for (size_t i = 0; i < mat->rows; i++) {
        for (size_t j = 0; j < mat->cols; j++) {
            result->data[j][i] = mat->data[i][j];
        }
    }
    
    return result;
}

// Utility functions
void matrix_print(const Matrix* mat) {
    printf("Matrix %zux%zu:\n", mat->rows, mat->cols);
    for (size_t i = 0; i < mat->rows; i++) {
        printf("[ ");
        for (size_t j = 0; j < mat->cols; j++) {
            printf("%8.2f ", mat->data[i][j]);
        }
        printf("]\n");
    }
}

bool matrix_equals(const Matrix* mat1, const Matrix* mat2, double epsilon) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        return false;
    }
    
    for (size_t i = 0; i < mat1->rows; i++) {
        for (size_t j = 0; j < mat1->cols; j++) {
            if (fabs(mat1->data[i][j] - mat2->data[i][j]) > epsilon) {
                return false;
            }
        }
    }
    
    return true;
}