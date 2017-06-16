#include <stdio.h>
#include <iostream>
#include <vector>
#include "math.cpp"

int main() {

  matrix <float> a(3,3);
  //a.multiply_scaler(2);
  a.print();
  std::vector<float> v {1,2,3};

  matrix<float> b = a.multiply_vector(&v);

  b.print();


  std::vector<float> v_out = a.multiply_vector_dot(&v);

  print_vector(v_out);

  return 0;
}
