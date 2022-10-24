#include <iostream>
#include <cstdlib>

class long_num {
private:
  int *num;
  int length;
  
public:
  long_num();
  ~long_num();
  long_num* set(const char *szlNum);
  long_num* sum(long_num* lNum);
  long_num* div(long_num* lNum);
  void print();
};