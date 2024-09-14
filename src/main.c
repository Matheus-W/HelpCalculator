#include "calc/calc.h"
#include <stdio.h>

int main()
{

    printf("HELP CALCULATOR\n\n");

    float test[] = { 2.1, 2.0, 2.5 };
    float av = average(3, test);

    float deviation = standard_deviation(3, test);

    printf("Media %f\n", av);
    printf("Desvio padrao %f\n", deviation);

    get_value_uncertainty(3, test, 0.1, 2.13);

    return 0;
}