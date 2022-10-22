#include "calculate.h"

calculate_returned calculate_integral (long double a, 
                                        long double b, 
                                        long double * Integral, 
                                        long double eps) {
  long double s1, s2, S; /* S = s1 + 2*s2  */
  long double q1, q2, Q; /* Q = q1 + 2*q2  */   /* q1 = (s1 + s2)/2   */
  int i, n=10;
  long double h = (b-a)/(2*n);

  s1 = (function(a)+function(b))*0.5;
  for (i=1, s2 = function(a+h); i<n; i++) {
      s1 += function(a+2*i*h);
      s2 += function(a+(2*i+1)*h);
  }
  s1 *= 2*h/3;
  s2 *= 2*h/3;
  S = (s1 + 2*s2);

  for (n=20; n<MAX_N; n*=2) {
      h = (b-a)/(2*n);
      for (i=0, q2=0; i<n-1; i++)
          q2 += function(a + (2*i+1)*h);

      q2 *= 2*h/3;
      q1 = 0.5*(s1+s2);
      Q = s1 + 2*s2;

      if (fabsl(S-Q)<eps)
          break;

      s1 = q1;
      s2 = q2;
      S = Q;
  }

  if (n>=MAX_N)
      return calculate_returned::not_applicable;

  *Integral = S;
  return calculate_returned::success;

}




calculate_returned calculate_improper_integral (long double a,
                                                long double * Integral,
                                                long double eps) {

  long double h;
  long double b;
  long double I=0, S=0;
  calculate_returned ret;

  for (h=1; h<MAX_H; h*=2, a=b)
  {
      b = a+h;
      ret = calculate_integral(a, b, &I, eps);
      if (ret==calculate_returned::not_applicable)
          return ret;
      S += I;
      if (fabsl(I)<eps)
          break;
  }

  *Integral=S;
  return calculate_returned::success;


}
