#include <vector>
// #include <iostream>
#include <algorithm>
#include <gtest/gtest.h>
using namespace std;

int find_middle (const vector<int> &arr){
    const size_t N = arr.size();

    if (N == 0)
    {
        throw invalid_argument("Cannot find the middle of an empty vector.");
    }
    
    vector <int> copy = arr;

    sort(copy.begin(),copy.end());
    int result = copy[N/2];
    return result;
}

TEST(OddCase,BaseCases)
{
    vector<int> vec {9,4,1,11,20,-1,2};
    int actual = find_middle(vec);

    EXPECT_EQ(4,actual);
}

TEST(EvenCase,BaseCases)
{
    vector<int> vec {9,4,11,20,-1,2};
    int actual = find_middle(vec);

    EXPECT_EQ(9,actual);
}

TEST(CheckEmptyVector,BaseCases)
{
    EXPECT_THROW({
        vector<int> vec;
        find_middle(vec);
    },invalid_argument);
}