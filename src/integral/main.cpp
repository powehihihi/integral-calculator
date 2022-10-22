#include "function.h"
#include "calculate.h"
#include <iostream>
#include <cstring>
#include <sstream>

int main(int argc, char * argv[]) {
  long double a, b;
  long double Integral;
  long double eps = 1e-14;
  calculate_returned returned;
  
  if (argc==4) {
    std::istringstream iss (argv[3]);
    if (!(iss >> eps)) {
      std::cout << "Cannot read eps!" << std::endl;
      return -1;
    }
  }
  else if (argc!=3) {
    std::cout << "Usage: a b (eps) F(x)" << std::endl;
    return -1;
  }
  
  std::istringstream iss (argv[1]);
  if (!(iss >> a)) {
    std::cout << "Cannot read eps!" << std::endl;
    return -1;
  }

  if (!strcmp(argv[2], "inf") || !strcmp(argv[2], "+inf")) {
   returned = calculate_improper_integral(a, &Integral, eps);
  }
  else {
  std::istringstream iss (argv[2]);
    if (!(iss>>b)) {
      std::cout << "Cannot read b!" << std::endl; 
      return -1;
    }
    returned = calculate_integral (a, b, &Integral, eps);
  }

  switch (returned) {
    case calculate_returned::success:
      std::cout << "Integral = " << Integral << std::endl;
      break;
    case calculate_returned::not_applicable:
      std::cout << "Unfortunatelly, my method is not applicable." << std::endl;
      break;
  }
  return 0;
}
