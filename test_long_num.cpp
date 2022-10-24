#include <iostream>
#include "long_num.h"

int main() {
  long_num num1, num2;
  num1.set("1000010101000100010100000010010101000010");
  num2.set("110000000000000");
  num1.sum(&num2);
  num1.print();
  std::cout << std::endl;
  num2.print();
  system("pause");
}