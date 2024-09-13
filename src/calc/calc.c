#include "calc.h"
#include <stdio.h>
#include <math.h>

float average(int length, float array[])
{
    float sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return sum / length;
}

float standard_deviation(int numSamples, float samples[])
{
    float avrg = average(numSamples, samples);
    float sum = 0;
    float temp = 0;
    float deviation = 0;

    for (size_t i = 0; i < numSamples; i++)
    {
        temp = samples[i] - avrg;
        sum += pow(temp, 2);
    }

    deviation = sqrt((sum / (numSamples - 1)));
    
    return deviation;
}