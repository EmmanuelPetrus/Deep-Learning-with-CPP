#include <gtest/gtest.h>
#include <cmath>

float sigmoid(float z)
{
    float result;
    if (z >= 45.f)
        result = 1.f;
    else if(z <= -45.f)
        result = 0.f;
    else 
        result = 1.f/(1.f + exp(-z));
    return result;
}

TEST(SigmoidTest,BaseCases)
{
    float actual = sigmoid(-100.);
    float expected = 0;

    EXPECT_NEAR(actual,expected,1e-7f) <<"Sigmoid lower bound test failed";
    EXPECT_NEAR(sigmoid(100.),1.,1e-7f) << "Sigmoid upper bound test failed";
    EXPECT_NEAR(sigmoid(.0),.5,1e-7f) << "Sigmoid center position test failed";
}
