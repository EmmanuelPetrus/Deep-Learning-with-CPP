#include <iostream>
#include <algorithm>
#include <numeric>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
    Matrix3i A,B;
    int total_size = A.size() + B.size();

    vector <int> holder (total_size,0);

    A << 98, 3, 45,
        7, 26 , 48,
        12, 14, 190;

    B << 4, 29, 1,
         3, 8, 10,
         11, 28, 50;

    auto smallest = [&holder,total_size](const Matrix3i A, const Matrix3i B, int sort_key){
        holder.clear();
        holder.insert(holder.end(), A.data(), A.data() + A.size());
        holder.insert(holder.end(), B.data(), B.data() + B.size());

        sort(holder.begin(),holder.end());

        for (int i = 0; i < sort_key; i++)
            cout << holder[i] << " ";
        cout << endl;
    };

    smallest(A,B,18);
    
    return 0;
}
