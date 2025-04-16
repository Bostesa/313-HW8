#include "matrix.h"
#include <stdio.h>

int main() {
    // Initialize matrix A
    double a_data[] = {6, 4, 8, 3};
    Matrix* A = matrix_create_from_array(a_data, 2, 2);
    
    // Initialize matrix B
    double b_data[] = {1, 2, 3, 4, 5, 6};
    Matrix* B = matrix_create_from_array(b_data, 2, 3);
    
    // Initialize matrix C
    double c_data[] = {2, 4, 6, 1, 3, 5};
    Matrix* C = matrix_create_from_array(c_data, 2, 3);
    
    // Print the input matrices
    printf("Matrix A:\n");
    matrix_print(A);
    printf("\nMatrix B:\n");
    matrix_print(B);
    printf("\nMatrix C:\n");
    matrix_print(C);
        
    // Step 1: Calculate 3 * B
    Matrix* B_scaled = matrix_scalar_multiply(B, 3);
    printf("\n3 * B:\n");
    matrix_print(B_scaled);
    
    // Step 2: Calculate C^T 
    Matrix* C_transpose = matrix_transpose(C);
    printf("\nC^T:\n");
    matrix_print(C_transpose);
    
    // Step 3: Calculate (3 * B) × C^T
    Matrix* product = matrix_multiply(B_scaled, C_transpose);
    printf("\n(3 * B) * C^T:\n");
    matrix_print(product);
    
    // Step 4: Calculate A + (3 * B) × C^T
    Matrix* D = matrix_add(A, product);
    printf("\nD = A + (3 * B) * C^T:\n");
    matrix_print(D);
    
    // Clean up
    matrix_destroy(A);
    matrix_destroy(B);
    matrix_destroy(C);
    matrix_destroy(B_scaled);
    matrix_destroy(C_transpose);
    matrix_destroy(product);
    matrix_destroy(D);
    
    return 0;
}