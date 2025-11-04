#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <string>

std::random_device rd {};

int main()
{
    std::mt19937 random_generator {rd()};

    // std::normal_distribution<>distro{2,3};
    std::uniform_real_distribution<> distro {-10,13};

    std::map<int, int> histogram;

    for (int i = 0; i < 10'000; ++i)
    {
        int val = std::round(distro(random_generator));
        histogram[val]++;
    }
    
    for (auto [x,y] : histogram)
    {
        std::cout << std::setw(2) << x <<' '<<std::string(y/20,'*')<<std::endl;
    }
    
    return 0;
}
