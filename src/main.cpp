
#include "iterator.hpp"
#include "matrix.hpp"
#include <vector>
#include <cstddef>
#include <iostream>

int main() {

    int array[100] = {1, 2, 3, 4, 5, 6, 7, 8};

    MatrixIterator<int> Tmp {array};

    std::cout << "*Tmp: " << *Tmp << '\n';
    std::cout << "*Tmp++: " << *++Tmp << '\n';
    std::cout << "*Tmp: " << *Tmp << '\n';
}