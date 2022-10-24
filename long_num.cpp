#include "long_num.h"

long_num::long_num() {
}

long_num::~long_num() {
  if (this->num != NULL)
    delete [] this->num;
}

long_num* long_num::set(const char *szlNum) {
  //проосчет длины числа
  this->length = 0;
  while(szlNum[this->length] != '\0') {
    this->length++;
  }
  
  if (this->num != NULL)
    delete [] this->num;
  this->num = new int[this->length];
  
  for (int i = 0; i < this->length; i++) {
    this->num[i] = 0;
  }
  //перевод строки в массив чисел
  int pos = 0;
  for (int i = this->length - 1; i >= 0; i--) {
    this->num[pos] = szlNum[i] - 0x30;
    pos++;
  }
  
  return this;
}

long_num* long_num::sum(long_num *lNum) {
  if (this->num != NULL && lNum->num != NULL) {
    //подсчет длины 
    int Length = 0;
    if (this->length > lNum->length) {
      Length = this->length + 1;
    }
    else {
      Length = lNum->length + 1;
    }
    //создание 2-х буферных массивов
    int *num1, *num2;
    num1 = new int[this->length]; 
    for (int i = 0; i < Length; i++) {
      num1[i] = 0;
      if (i < this->length)
        num1[i] = this->num[i];
    }
    num2 = new int[this->length];
    for (int i = 0; i < Length; i++) {
      num2[i] = 0;
      if (i < lNum->length)
        num2[i] = lNum->num[i];
    }
    this->length = Length;
    //поразрядное сложение
    for (int i = 0; i < Length; i++) {
      num1[i] += num2[i];
      num1[i + 1] += (num1[i] / 10);
      num1[i] %= 10;
    }
    //копирование данных из буфера в основной массив
    delete [] this->num;
    this->num = new int[this->length];
    for (int i = 0; i < this->length; i++) {
      this->num[i] = num1[i];
    }
    
    if (this->num[this->length - 1] == 0)
      this->length--;
    
    return this;
}

long_num* long_num::div(long_num *lNum) {
  
}

void long_num::print() {
  for (int i = this->length - 1; i >= 0; i--)
    std::cout << num[i];
}