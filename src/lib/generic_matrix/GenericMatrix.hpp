#ifndef OVERLOADED_OPPS_HPP
#define OVERLOADED_OPPS_HPP

#include <vector>

// This entity represents a 2D vector, we will declare and define
// all of its valid operands
template<typename T>
class Matrix
{
public:
    Matrix();

    // Destructor
    ~Matrix();

    // Copy Constructor
    Matrix(Matrix<T>& matrix);

    // Move Constructor
    Matrix(Matrix<T> &&matrix);

    // Assignment operator
    Matrix<T> operator=(Matrix<T> &matrix);

    Matrix(std::initializer_list<T> &list);

/// Accessor operators
public:
    T operator[](int i);

/// Arithmetic operators
public:
    // Needs to return a Matrix copy
    Matrix<T> operator+ (Matrix<T> &right);

    // Needs to return a Matrix copy
    Matrix<T> operator- (Matrix<T> &right);

    bool operator++(int) = delete;

    bool operator--(int) = delete;

/// Comparison operators
public:

    Matrix operator* (Matrix<T> &right);

    bool operator== (Matrix<T> &right); 

    bool operator< (Matrix<T> &right);

    bool operator> (Matrix<T> &right);

    bool operator<= (Matrix<T> &right);

    bool operator>= (Matrix<T> &right);

private:

    std::vector<std::vector<T>> matrix_;
    size_t rows_;
    size_t cols_;
};
#include "Matrix.tpp"

#endif
