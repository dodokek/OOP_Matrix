
#include "matrix.hpp"
#include <vector>
#include <cstddef>
#include <iostream>

int main() {

    std::vector<int> tmp{1,2,3,4,5,6};
    std::vector<int> tmp2{2222222,2,3,4,5,6};

    Matrix<int> TestMatrix(3, 2, tmp.begin(), tmp.end());
    Matrix<int> AnotherMatrix(3, 2, tmp2.begin(), tmp2.end());

    AnotherMatrix = std::move(TestMatrix);
    AnotherMatrix.Dump();
}