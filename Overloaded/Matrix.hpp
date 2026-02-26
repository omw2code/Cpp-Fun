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
    Matrix(T& matrix);

    // Move Constructor
    Matrix(T &&matrix);

    // Assignment operator
    Matrix operator=(Matrix<T> &matrix);

    Matrix(std::initializer_list<T> &list);

public:
    // Needs to return a Matrix copy
    Matrix operator+ (Matrix<T> &right);

    // Needs to return a Matrix copy
    Matrix operator- (T &right);

    // Needs to return a Matrix copy
    Matrix operator* (Matrix<T> &right);

    bool operator== (T &right); 

    bool operator< (T &right);

    bool operator> (T &right);

    bool operator<= (T &right);

    bool operator>= (T &right);

    bool operator++(int) = delete;

    bool operator--(int) = delete;

private:

    std::vector<std::vector<T>> matrix_;
    size_t rows_;
    size_t cols_;
};
#include "Matrix.tpp"

#endif
