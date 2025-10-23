#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    bool flag = true;
    int score = 92;
    double average = 82.50;

    cout << "A variable of type bool" << endl;
    cout << "Size: " << sizeof(flag) << " ";
    cout << "Value: " << flag << " ";
    cout << "Address: "<< &flag << endl << endl;
    // Printing size, value, and address of the score variable
    cout << "A variable of type int" << endl;
    cout << "Size: " << sizeof (score) << " " ;
    cout << "Value: " << score << " ";
    cout << "Address: "<< &score << endl << endl;
    // Printing size, value, and address of the average variable
    cout << "A variable of type double" << endl;
    cout << "Size: " << sizeof (average) << " " ;
    cout << "Value: " << average << " ";
    cout << "Address: "<< &average << endl;
    return 0;
}
