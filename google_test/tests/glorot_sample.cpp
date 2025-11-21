#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include <boost/math/distributions/chi_squared.hpp>
#include <boost/math/distributions/students_t.hpp>
#include <gtest/gtest.h>

using namespace boost::math;
using namespace std;

vector<float> glorot_initializer(int fan_in,int fan_out){
    int size = fan_in * fan_out;
    float std_dev = sqrt(2./(fan_in + fan_out));

    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    std::normal_distribution<float> distribution(0.0f,std_dev);

    vector<float> result(size);
    generate(result.begin(),result.end(),[&generator,&distribution](){return distribution(generator);});

    return result;
}

bool chi_squared_test(float population_std,float sample_std, int sample_size, float confidence)
{
    float variance_rate = sample_std / population_std;
    variance_rate = variance_rate*variance_rate;
    float t_stat = (sample_size-1)*variance_rate;

    chi_squared distro(sample_size-1);

    float upper_limit = quantile(complement(distro,confidence/2));
    float lower_limit = quantile(distro,confidence/2);

    return t_stat > upper_limit && t_stat < lower_limit;
}

bool t_test(float population_mean, float sample_mean, float sample_std_dev, int sample_size, int confidence)
{
    float diff = sample_mean - population_mean;
    float t_stat = diff * sqrt(double(sample_size));
    unsigned degree_of_freedom = sample_size -1;
    students_t distro(degree_of_freedom);
    float q = cdf(complement(distro,fabs(t_stat)));

    float confidence_2 = confidence / 2.;

    return q < confidence_2;

}

TEST(CheckGlorot,StatCases)
{
    int fan_in = 6;
    int fan_out = 5;

    auto weights = glorot_initializer(fan_in,fan_out);

    const int N = weights.size();

    EXPECT_EQ(N,fan_in*fan_out);

    float sum = accumulate(weights.begin(),weights.end(),0.0);
    float weight_mean = sum / N;

    float acc = 0.0;

    auto differ = [&acc, &weight_mean](const float val)
    {
        const float diff = val - weight_mean;
        acc += diff * diff;
    };

    for_each(weights.begin(),weights.end(),differ);

    float actual_stdev = sqrt(acc/(N-1));

    float expected_stdev = sqrt(2. / (fan_in+fan_out));

    bool std_dev_rejected = chi_squared_test(expected_stdev,actual_stdev,N,0.06);

    if (std_dev_rejected)
    {
        FAIL() << "The weights standad deviatioin do no look like expected by the Glorot initialaizer";
    }

    bool mean_rejected = t_test(0.,weight_mean,actual_stdev,N,0.05);

    if (mean_rejected)
    {
        FAIL() << "The weights mean do not look expected by the Glorot initializer";
    }
}