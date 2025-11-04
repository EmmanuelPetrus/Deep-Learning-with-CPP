#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
    Matrix3i A;
    Matrix3i B;
    A << 1, 10, 4,
         2, 9,  6,
         3, 11, 7;

   
    cout << A.colwise().reverse()<<endl<<endl;
    cout << A.rowwise().reverse();

    return 0;
}
