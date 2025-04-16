#include "Matrix1.h"
#include <iostream>

int main() {
    // Define matrices 
    Matrix A = {
        {6, 4},
        {8, 3}
    };
    
    Matrix B = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    Matrix C = {
        {2, 4, 6},
        {1, 3, 5}
    };
    
    // Print the input matrices
    std::cout << "Matrix A:" << std::endl << A << std::endl;
    std::cout << "Matrix B:" << std::endl << B << std::endl;
    std::cout << "Matrix C:" << std::endl << C << std::endl;
      
    // Step 1: Calculate 3 * B
    Matrix B_scaled = B * 3;
    std::cout << "3 * B:" << std::endl << B_scaled << std::endl;
    
    // Step 2: Calculate C^T 
    Matrix C_transpose = C.transpose();
    std::cout << "C^T:" << std::endl << C_transpose << std::endl;
    
    // Step 3: Calculate (3 * B) × C^T
    Matrix product = B_scaled * C_transpose;
    std::cout << "(3 * B) * C^T:" << std::endl << product << std::endl;
    
    // Step 4: Calculate A + (3 * B) × C^T
    Matrix D = A + product;
    std::cout << "D = A + (3 * B) * C^T:" << std::endl << D << std::endl;
    
    return 0;
}