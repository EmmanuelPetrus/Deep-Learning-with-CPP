#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
    Matrix3i A;
    Matrix3i B;
    A << 1, 2, 3,
         4, 5,  6,
         7, 8, 9;

    B = A.transpose().rowwise().reverse();
    cout << B << endl;
   
    return 0;
}
