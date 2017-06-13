#include <stdio.h>
#include <iostream>
#include <vector>
#include "math.cpp"

int main() {

  matrix <double> a(3,3);
  //a.multiply_scaler(2);
  a.print();
  std::vector<double> v {1,2,3};

  matrix<double> b = a.multiply_vector(&v);

  b.print();


  std::vector<double> v_out = a.multiply_vector_dot(&v);

  print_vector(v_out);

  return 0;
}
