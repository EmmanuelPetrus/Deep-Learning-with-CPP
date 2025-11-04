#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;
using namespace std;

int main() {
    MatrixXd A(2,2);
    A(0,0) = 2;
    A(1,0) = -2;
    A(0,1) = 3;
    A(1,1) = 1;

    MatrixXd B(2,3);
    B(0,0) = 1;
    B(1,0) = 1;
    B(0,1) = 2;
    B(1,1) = 2;
    B(0,2) = -1;
    B(1,2) = 1;

    auto C = A * B;
    // auto D = B.cwiseProduct(C);

    // cout <<"A:\n" << A << endl;
    // cout <<"B:\n" << B << endl;
    // cout <<"C:\n" << C << endl;
    // cout <<"D:\n" << D << endl;
    // cout << "The inverse of A is:\n" << A.inverse() << std::endl;
    // cout << "The determinant of A is:\n" << C.determinant() << endl;
    // cout << "The transpose of B is:\n" << B.transpose() << endl;

    cout << "Example of unary operation:\n\n";
    auto func_X_X = [](double x){return x * x;};
    cout << A.unaryExpr(func_X_X) << endl;
    return 0;
}
