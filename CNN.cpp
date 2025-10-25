#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

vector < vector<double> >CNN_computation(const vector < vector<double> > &X,const vector < vector<double> > &kernel );
void printVector(const vector< vector<double> >&result);
vector < vector<double> > inputMatrix(vector < vector<double> > &A,int& rows,int& cols);

int main(int argc, char const *argv[])
{
    int rowsA,colsA,rowsB,colsB = 0 ;
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

    vector < vector<double> > matrixA(rowsA, vector<double>(colsA,0));
    vector < vector<double> > kernel(rowsB, vector<double>(colsB,0));
    vector < vector<double> > result(rowsA, vector<double>(colsB,0));

    
    
    
    matrixA = inputMatrix(matrixA,rowsA,colsA);
    kernel = inputMatrix(kernel,rowsB,colsB);
    
     
    result = CNN_computation(matrixA,kernel);
    printVector(result);
    
}


vector < vector<double> >CNN_computation(const vector < vector<double> > &X,const vector < vector<double> > &kernel )
{
    int outRows = X.size() - kernel.size() + 1;
    int outCols = X[0].size() - kernel[0].size() + 1;
    int K = kernel.size();
    int L = kernel[0].size();
    
    cout << "OutRows:" << outRows << endl;
    cout << "OutCols:" << outCols << endl;
    cout << "K:" << K << endl;
    cout << "L:" << L << endl;

    vector < vector<double> > Y(outRows,vector<double>(outCols,0));

    for (int i = 0; i < outRows; i++)
    {
        for (int j = 0; j < outCols; j++)
        {
            int sum = 0;
            for (int u = 0; u < K; u++)
            {
                for (int v = 0; v < L; v++)
                {
                    sum+=X[i+u][j+v]*kernel[u][v];
                }
                
            }
            cout << "Sum:" << sum<<endl;
            Y[i][j] = sum;
        }
        
    }
    return Y;
}

void printVector(const vector< vector<double> >&result)
{
    int cols = result[0].size();

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