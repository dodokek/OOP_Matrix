#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <utility>

#include "iterator.hpp"

template <typename T>
class Matrix final {
public: 
    using size_type = std::size_t;

private:
        T* data_;
        size_type n_line_;
        size_type n_row_;
        size_type capacity_;
    // ------------------------------------------

public:
// Constructors && Rule of 5

    template<typename Iter>
    Matrix (size_type n_line, size_type n_row, Iter begin, Iter end) : 
        data_(new T[n_line * n_row]),
        n_row_(n_row),
        n_line_(n_line),
        capacity_(n_line * n_row)
    {
        if (std::distance(begin, end) != capacity_) {
            throw std::invalid_argument{"iterated container hasn't got the same size as matrix"};
        }
        std::copy(begin, end, data_);
    }

    Matrix (size_type n_line, size_type n_row, std::istream& is) 
        : data_(new T[n_line * n_row]),
          n_row_(n_row),
          n_line_(n_line),
          capacity_(n_line * n_row)
    {
        for (size_type i = 0; i < capacity_; i++) {
            T tmp_input;

            is >> tmp_input;
            if (!is.good())
                throw std::runtime_error{"Error occured while reading data"};

            data_[i] = tmp_input;
        }
    }

    Matrix (size_type n_line, size_type n_row, const T& value_to_fill) 
        : data_(new T[n_line * n_row]),
          n_row_(n_row),
          n_line_(n_line),
          capacity_(n_line * n_row)
    {
        std::fill (data_, data_ + capacity_, value_to_fill);
    }

    
    Matrix (const Matrix& rhs) :
        n_line_(rhs.n_line_),
        n_row_(rhs.n_row_),
        capacity_(rhs.capacity_),
        data_(new T[capacity_])
    {
        std::copy(rhs.data_, rhs.data_ + capacity_, data_);
    }

    Matrix (Matrix&& rhs) :
        n_line_(std::exchange(rhs.n_line_, 0)),
        n_row_(std::exchange(rhs.n_row_, 0)),
        capacity_(std::exchange(rhs.capacity_, 0)),
        data_{std::exchange(rhs.data_, nullptr)} { }

    Matrix& operator=(const Matrix& rhs) {
        n_line_ = rhs.n_line_;
        n_row_ = rhs.n_row_;
        capacity_ = rhs.capacity_;
        std::copy(rhs.data_, rhs.data_ + rhs.capacity_, data_);
    
        return *this;
    }

    Matrix& operator=(Matrix&& rhs) {
        delete[] data_;

        data_ = std::exchange(rhs.data_, nullptr);
        n_line_ = std::exchange(rhs.n_line_, 0);
        n_row_ = std::exchange(rhs.n_row_, 0);
        capacity_  = std::exchange(rhs.capacity_, 0);

        return *this;
    }

    ~Matrix () {
        delete[] data_;
    }

// =================== Functionality


// Class of proxy bracket for operator [][]
class SecondBracket {
private:
    T* data_pointer_;

public: 
    SecondBracket (T* ptr) : data_pointer_(ptr) { }

    T& operator[](size_type indx) {
        return data_pointer_[indx];
    }

    const T& operator[](size_type indx) const {
        return data_pointer_[indx];
    } 

}; // Class SecondBracket. End.


    SecondBracket operator[](size_type indx){
        return SecondBracket(data_ + indx * n_row_);
    }

    const SecondBracket operator[](size_type indx) const {
        return SecondBracket(data_ + indx * n_row_);
    }


    void Dump() {
        for (size_type i = 0; i < n_line_; i++) {
            for (size_type j = 0; j < n_row_; j++){
                std::cout << data_[i*n_row_ + j] << ' ';
            }
            std::cout << '\n';
        }
    }



}; // Class Matrix. End.
