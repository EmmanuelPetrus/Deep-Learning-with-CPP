#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    vector < function<bool(double,double)> >comparators
    {
        less<double>(),
        less_equal<double>(),
        greater<double>(),
        greater_equal<double>()
    };

    double x = 10;
    double y = 10;

    auto compare = [&x,&y](const function<bool(double,double)>&comparator)
    {
        bool b = comparator(x,y);
        cout << (b?"TRUE":"FALSE") << "\n";
    };

    for_each(comparators.begin(),comparators.end(),compare);

    return 0;
}
