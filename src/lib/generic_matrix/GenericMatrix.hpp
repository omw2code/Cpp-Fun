#ifndef OVERLOADED_OPPS_HPP
#define OVERLOADED_OPPS_HPP

#include <vector>
#include <type_traits>

// This entity represents a 2D vector, we will declare and define
// all of its valid operands
template<typename T>
class GenericMatrix
{
public:
    /*
    * Default constructor
    */
    GenericMatrix();

    /*
    * Default destructor
    */
    ~GenericMatrix();

    /*
    * Copy Constructor
    */
    GenericMatrix(const GenericMatrix<T>& other);

    /*
    * Move Constructor
    */
    GenericMatrix(GenericMatrix<T> &&matrix) noexcept;

    GenericMatrix<T>& operator=(GenericMatrix<T> &&other) noexcept;

    /*
    * Assignment operator
    */
    GenericMatrix<T> operator=(GenericMatrix<T> &other);

    GenericMatrix(const std::initializer_list<std::initializer_list<T>> &list);

/// Accessor operators
public:
    T operator[](int i);

/// Arithmetic operators
public:
    // Needs to return a GenericMatrix copy
    GenericMatrix<T> operator+ (GenericMatrix<T> &right);

    // Needs to return a GenericMatrix copy
    GenericMatrix<T> operator- (GenericMatrix<T> &right);

    bool operator++(int) = delete;

    bool operator--(int) = delete;

/// Comparison operators
public:

    GenericMatrix operator* (GenericMatrix<T> &right);

    bool operator== (GenericMatrix<T> &right); 

    bool operator< (GenericMatrix<T> &right);

    bool operator> (GenericMatrix<T> &right);

    bool operator<= (GenericMatrix<T> &right);

    bool operator>= (GenericMatrix<T> &right);

private:

    std::vector<std::vector<T>> matrix_;
    size_t rows_;
    size_t cols_;
};
#include "GenericMatrix.tpp"

#endif
