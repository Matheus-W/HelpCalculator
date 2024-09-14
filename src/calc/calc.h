#ifndef CALC_H
#define CALC_H

#define DIGITAL_INSTRUMENT 12.0;

typedef struct 
{
    float Average;
    float StandartDeviation;
    float CombinedUncertainty;
    float InstrumentResolution;
    float ExpandedUncertainty;
    float StudentCoefficient;
} CalcSolution;


float average(int length, float array[]);

float standard_deviation(int numSamples, float samples[]);

float combined_uncertainty(int numSamples, float samplesAverage);

float resolution_digital_instrument_uncertainty(float resolution);

float expanded_uncertainty(float combined, float instrument, float studentCoefficient);

CalcSolution get_value_uncertainty(int numSamples, float samples[], float instResolution, float studentCoefficient);

#endif