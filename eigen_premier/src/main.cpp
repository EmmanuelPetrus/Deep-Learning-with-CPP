#include <Eigen/Dense>
#include <iostream>

int main() {
    Eigen::Matrix2d A;
    A << 1, 2,
         3, 4;
    std::cout << "Matrix:\n" << A << "\nDeterminant: " << A.determinant() << std::endl;
    return 0;
}
