#include <type_traits>
#include "Matrix.hpp"

template<typename T>
Matrix<T>::Matrix()
{}

template<typename T>
Matrix<T>::~Matrix()
{}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<T> &list)
  : matrix_(list)
{}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &rhs)
{
    // Ensure this and T are the same type
    if constexpr ( !std::is_same<decltype(this), decltype(rhs)>::type )
        throw std::invalid_argument("Invalid binary operand using the + operator");
    
    int r_rows = rhs.size();
    if constexpr ( r_rows != rows_ )
        throw std::length_error("Invalid operand row size using + operator");

    int r_cols = rhs[0].size();
    if constexpr ( r_cols != cols_ )
        throw std::length_error("Invalid operand col size using the + operator");

    Matrix<T> matrix;
    for (int i{}; i < rows_; ++i)
    {
        for (int j{}; j < cols_; ++j)
        {
            matrix[i][j] = this[i][j] + rhs[i][j];
        }
    }
    return matrix;
}




template<typename T>
 Matrix<T> Matrix<T>::operator*(Matrix<T> &rhs)
{
    // Start matrix multiplication
    Matrix<T> matrix;
    for (int i{}; i < rows_; ++i)
    {
        for(int j{}; j < cols_; ++j)
        {
            for(int k{}; k < rhs.size(); ++k)
            {
                matrix[i][j] = this[i][j] * rhs[i][j];
            }
        }
    }
    return matrix;
}
