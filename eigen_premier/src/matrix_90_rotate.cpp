#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
    Matrix3i A;
    Matrix3i B,C;
    A << 1, 2, 3,
         4, 5,  6,
         7, 8, 9;

    B = A.transpose().rowwise().reverse(); //rotate clockwise
    C = A.transpose().colwise().reverse(); //rotate anticlockwise 
    cout << B << endl << endl << endl;
    cout << C << endl;
    return 0;
}
