#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    // give lambda function a name and call it
    // auto func = [](){
    //     cout << "Hello World!" << endl;
    // };

    // func();

    // call a lambda function directly after definition 
    // [](){
    //     cout << "Hello World!" << endl;
    // }();

    // Define a lambda that takes parameters

    // [](int a, int b){
    //     cout << " a + b = " << a + b << endl;
    // }(7,3);


    // Define a lambda that returns something
    // int sum = [](int a, int b)->int{
    //     return a + b;
    // }(7,3);

    // cout <<"The sum is : "<< [](int a, int b)->int{
    //     return a + b;
    // }(7,3) << endl;
    // return 0;

    // capture lists 
    // int a = 7;
    // int b = 3;

    // [a,b](){
    //     cout << " a is : "<< a << endl;
    //     cout << " b is : "<< b << endl;
    // }();

    // capturing by value 
    // int c = 42;

    // auto func = [c](){
    //     cout << "The inner value of c is : " << c << endl;
    // };

    // for (int i = 1; i < 5; i++)
    // {
    //     cout << "The outer value of c is : " << c << endl;
    //     func();
    //     c += 1;
    // }

    // capturing by reference 
    // int c = 42;

    // auto func = [&c](){
    //     cout << "The inner value of c is : " << c << endl;
    // };

    // for (int i = 1; i < 5; i++)
    // {
    //     cout << "The outer value of c is : " << c << endl;
    //     func();
    //     c += 1;
    // }

    // capturing by value
    int c = 42;

    auto func = [=](){
        cout << "The inner value of c is : " << c << endl;
    };

    for (int i = 1; i < 5; i++)
    {
        cout << "The outer value of c is : " << c << endl;
        func();
        c += 1;
    }
    
}
