#include <cstddef>

#include "arr.hpp"
#include "vector.hpp"
using std::cout;

int length(char* str) {
  int len = 0;
  while (*str++) {
    ++len;
  }
  return len;
}
int sum(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

void print_result(int (*func)(int, int), int one, int two) {
  cout << func(one, two) << std::endl;
}

int main(int argc, const char* argv[]) {
  int size = 7;
  int* array = new int[size];
  library::fill_array(array, size);
  library::print_array(array, size);
  library::push_back(array, size, 19);
  library::print_array(array, size);
  library::pop_back(array, size);
  library::print_array(array, size);
  return 0;
}