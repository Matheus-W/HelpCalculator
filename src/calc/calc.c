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

    for (size_t i = 0; i < numSamples; i++)
    {
        temp = samples[i] - avrg;
        sum += pow(temp, 2);
    }

    return sqrt((sum / (numSamples - 1)));
}

float combined_uncertainty(int numSamples, float samplesAverage)
{
    return samplesAverage / (sqrt(numSamples));
}

float resolution_digital_instrument_uncertainty(float resolution)
{
    float val = DIGITAL_INSTRUMENT;
    return resolution / (sqrt(val));
}

float expanded_uncertainty(float combined, float instrument, float studentCoefficient)
{
    float ua = pow(combined, 2);
    float ub = pow(instrument, 2);
    return studentCoefficient * sqrt((ua + ub));
}

CalcSolution get_value_uncertainty(int numSamples, float samples[], float instResolution, float studentCoefficient)
{
    CalcSolution calcSol;

    calcSol.Average = average(numSamples, samples);
    calcSol.StandartDeviation = standard_deviation(numSamples, samples);
    calcSol.CombinedUncertainty = combined_uncertainty(numSamples, calcSol.StandartDeviation);
    calcSol.InstrumentResolution = resolution_digital_instrument_uncertainty(instResolution);
    calcSol.ExpandedUncertainty = expanded_uncertainty(calcSol.CombinedUncertainty, calcSol.InstrumentResolution, studentCoefficient);
    calcSol.StudentCoefficient = studentCoefficient;

    return calcSol;
}