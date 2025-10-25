#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector< vector<double> > product(const vector< vector<double> > &A, const vector< vector<double> > &B);
void printVector(const vector< vector<double> >&result);
vector < vector<double> > inputMatrix(vector < vector<double> > &A,int& rows,int& cols);

int main(int argc, char const *argv[])
{
    int rowsA,colsA,rowsB,colsB = 0 ;
    vector < vector<double> > matrixA(rowsA, vector<double>(colsA,0));
    vector < vector<double> > matrixB(rowsB, vector<double>(colsB,0));
    vector < vector<double> > result(rowsA, vector<double>(colsB,0));

    cout << "Enter the dimensions of the first Matrix"<< endl;
    cout <<"RowsA:";
    cin >> rowsA;
    cout << "ColsA:";
    cin >> colsA;
    
    cout << "Enter the dimensions of the second Matrix"<< endl;
    cout <<"RowsB:";
    cin >> rowsB;
    cout << "ColsB:";
    cin >> colsB;
    
    
    matrixA = inputMatrix(matrixA,rowsA,colsA);
    matrixB = inputMatrix(matrixB,rowsB,colsB);
    
     if (matrixA[0].size() != matrixB.size())
    {
        cout << "Matrix not conformable for multiplication.";
        return 1;
    }

    result = product(matrixA,matrixB);
    printVector(result);
    
}


vector< vector<double> > product(const vector< vector<double> > &A, const vector< vector<double> > &B)
{
    int rowsA = A.size();
    int rowsB = B.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    
    vector < vector<double> >result(rowsA, vector<double>(colsA,0));

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            double sum = 0;
            for (int k = 0; k < colsA; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

void printVector(const vector< vector<double> >&result)
{
    int cols = 3;

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << result[i][j] << setw(6); 
    
        }
        cout << endl;
    }
}

vector < vector<double> > inputMatrix(vector < vector<double> > &A,int& rows,int& cols)
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) {
            cout << "Enter value for matrix[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
    return A;
}