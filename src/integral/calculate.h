#ifndef CALCULATE_H
#define CALCULATE_H
#include "function.h"

#define MAX_N (10000000)
#define MAX_H (1e200)


enum class calculate_returned {
  success,
  not_applicable,
};

calculate_returned calculate_integral (long double a, long double b, 
                                        long double * Integral, long double eps);

calculate_returned calculate_improper_integral (long double a,
                                                long double * Integral,
                                                long double eps);

#endif // !CALCULATE_H
