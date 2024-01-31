#pragma once

template <typename T>
class MatrixIterator final {
private: 
    T* pointer_;

public:
    MatrixIterator(T* pointer) : pointer_(pointer) {}

    T* GetPointer() const {
        return pointer_;
    }

    MatrixIterator operator+(int n) const { return {pointer_ + n}; }
    MatrixIterator operator-(int n) const { return {pointer_ - n}; }

    MatrixIterator operator++(int n) {pointer_++; return *this; }
    MatrixIterator operator--(int n) {pointer_--; return *this; }

    MatrixIterator operator++() {
        MatrixIterator<T> Tmp = {pointer_};
        pointer_++;
        return Tmp;
    }
    MatrixIterator operator--() {
        MatrixIterator<T> Tmp = {pointer_};
        pointer_--;
        return Tmp;
    }

    T& operator*() {return *pointer_;}

}; // MatrixIterator. End.
