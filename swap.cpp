#include <iostream>
using namespace std;

void swap(int& first, int& second);
int main(int argc, char const *argv[])
{
    int x = 10;
    int y = 20;

    cout << "Values of x and y before swapping."<<endl;
    cout <<"x:"<<x<<" "<<"y:"<<y<<endl;

    swap(x,y);

    cout << "Values of x and y after swapping."<<endl;
    cout <<"x:"<<x<<" "<<"y:"<<y;
    return 0;
}

void swap(int& rX,int& rY)
{
    int temp = rX;
    rX = rY;
    rY = temp;
}