#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    size_t rows;
    size_t cols;

public:
    // Default constructor
    Matrix() : rows(0), cols(0) {}
    
    // Constructor with dimensions 
    Matrix(size_t r, size_t c, double initialValue = 0.0) : rows(r), cols(c) {
        data.resize(rows, std::vector<double>(cols, initialValue));
    }
    
    // Constructor from initializer list 
    Matrix(std::initializer_list<std::initializer_list<double>> init) {
        rows = init.size();
        if (rows == 0) {
            cols = 0;
            return;
        }
        
        cols = init.begin()->size();
        data.resize(rows);
        
        size_t i = 0;
        for (const auto& row : init) {
            if (row.size() != cols) {
                throw std::invalid_argument("All rows must have the same number of columns");
            }
            data[i].resize(cols);
            
            size_t j = 0;
            for (const auto& val : row) {
                data[i][j] = val;
                j++;
            }
            i++;
        }
    }
    
    // Accessors
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }
    
    // Element access
    double& operator()(size_t i, size_t j) {
        if (i >= rows || j >= cols) {
            throw std::out_of_range("Matrix indices out of range");
        }
        return data[i][j];
    }
    
    const double& operator()(size_t i, size_t j) const {
        if (i >= rows || j >= cols) {
            throw std::out_of_range("Matrix indices out of range");
        }
        return data[i][j];
    }
    
    // Matrix operations
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }
        
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result(i, j) = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions must match for subtraction");
        }
        
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result(i, j) = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Number of columns in first matrix must equal number of rows in second matrix for multiplication");
        }
        
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < other.cols; j++) {
                double sum = 0.0;
                for (size_t k = 0; k < cols; k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                result(i, j) = sum;
            }
        }
        return result;
    }
    
    Matrix operator*(double scalar) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result(i, j) = data[i][j] * scalar;
            }
        }
        return result;
    }
    
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result(j, i) = data[i][j];
            }
        }
        return result;
    }
    
    // Display
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (size_t i = 0; i < m.rows; i++) {
            os << "[ ";
            for (size_t j = 0; j < m.cols; j++) {
                os << std::setw(8) << std::fixed << std::setprecision(2) << m.data[i][j];
                if (j < m.cols - 1) os << ", ";
            }
            os << " ]" << std::endl;
        }
        return os;
    }
};

// Non-member scalar multiplication
inline Matrix operator*(double scalar, const Matrix& mat) {
    return mat * scalar;
}

#endif // MATRIX_H