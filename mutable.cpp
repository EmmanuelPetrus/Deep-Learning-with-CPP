#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using Vector = vector<double>;

int main(int argc, char const *argv[])
{
    auto V = Vector();
    auto momentum_optimizer = [V]
    (const Vector &gradient) mutable
    {
        if (V.empty()) V.resize(gradient.size(),0.);
        transform(V.begin(),V.end(),gradient.begin(),V.begin(),[]
    (double v, double dx)
        {
            double beta = 0.7;
            return v = beta * v + dx;
        });
        return V;
    };

    auto print = [](double d){cout << d << " ";};

    const vector current_grads{1.,0.,1.,1.,0.,1.};
    for (int i = 0; i < 4; i++)
    {
        vector weight_update = momentum_optimizer(current_grads);
        for_each(weight_update.begin(),weight_update.end(),print);
        cout << "\n";
    }
    
    return 0;
}
