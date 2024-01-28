#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
class Matrix final {
public: 
    using size_type = std::size_t;

    // ------------------------------------------

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

    void Dump() {
        for (size_type i = 0; i < n_line_; i++) {
            for (size_type j = 0; j < n_row_; j++){
                std::cout << data_[i*n_row_ + j] << ' ';
            }
            std::cout << '\n';
        }
    }

private:

    T* data_;
    size_type n_line_;
    size_type n_row_;
    size_type capacity_;
};
