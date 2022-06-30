  // Copyright 2020 Oganyan Robert

#include <iostream>
#include "../include/utmatrix.h"


int main() {
  TMatrix<int> a(5);
  TMatrix<int> b(5), c(5);
  int i, j;
  std::cout << "Triangular Matrix test" << std::endl;
  for (i = 0; i < 5; i++) {
    for (j = i; j < 5; j++) {
      a[i][j] = i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  }
  c = a + b;
  auto d = a - b;
  std::cout << "Matrix a = " << std::endl << a << std::endl;
  std::cout << "Matrix b = " << std::endl << b << std::endl;
  std::cout << "Matrix c = a + b" << std::endl << c << std::endl;
  std::cout << "Matrix d = a - b" << std::endl << d << std::endl;
  return 0;
}

