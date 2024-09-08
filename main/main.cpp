// Copyright 2024 Marina Usova
#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"
#include "../lib_pair/pair.h"

int main() {
  int a, b;
  float result;

  a = 1; b = 4;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  a = 1; b = 0;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }
  Pair<int, double> p1(1, 3.14);
  Pair<int, double> p2(2, 2.71);

  std::cout << "p1: " << p1 << std::endl;
  std::cout << "p2: " << p2 << std::endl;

  Pair<int, double> p3 = p1 + p2;
  std::cout << "p3: " << p3 << std::endl;
  return 0;
}

#endif  // EASY_EXAMPLE
