#include "calc/calc.h"
#include <stdio.h>

void result_print(CalcSolution calc)
{
    printf("Media das amostras: %f\n", calc.Average);
    printf("Desvio padra: %f\n", calc.StandartDeviation);
    printf("Inscerteza combinada: %f\n", calc.CombinedUncertainty);
    printf("Inscerteza da medicao: %f\n", calc.InstrumentResolution);
    printf("Incerteza expandida da medicao: %f\n", calc.ExpandedUncertainty);
}

int main()
{
    printf("HELP CALCULATOR\n\n");
    
    int numberSamples;
    printf("Digite o numero de amostras: ");
    scanf("%d", &numberSamples);
    printf("\n");

    float samples[numberSamples];
    float studentCoefficient;
    float instrumentResolution;

    for (int i = 0; i < numberSamples; i++)
    {
        printf("Informe o valor da amostra %d: ", i + 1);
        scanf("%f", &samples[i]);
        printf("\n");
    }

    printf("Diga ao programa qual é o Coeficiente de Student: ");
    scanf("%f", &studentCoefficient);
    printf("\n");
    printf("Informe qual é a resolucao do instrumento digital de medicao: ");
    scanf("%f", &instrumentResolution);
    printf("\n");

    CalcSolution calcSolution = get_value_uncertainty(numberSamples, samples, instrumentResolution, studentCoefficient);

    result_print(calcSolution);

    return 0;
}