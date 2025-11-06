#include "my_functions.h"
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