#ifndef CALC_H
#define CALC_H

#define DIGITAL_INSTRUMENT 12.0;

float average(int length, float array[]);

float standard_deviation(int numSamples, float samples[]);

float combined_uncertainty(int numSamples, float samplesAverage);

float resolution_digital_instrument_uncertainty(float resolution);

float expanded_uncertainty(float combined, float instrument, float studentCoefficient);

void get_value_uncertainty(int numSamples, float samples[], float instResolution, float studentCoefficient);

#endif