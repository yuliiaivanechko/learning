#include <cstddef>
#include <stdexcept>

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
void test() {
  try {
    Vector<int> v(-2);
  } catch (const std::bad_alloc& err) {
    std::cerr << err.what() << std::endl;
  } catch (const std::length_error& err) {
    std::cerr << err.what() << std::endl;
  }
}

int main(int argc, const char* argv[]) {
  test();
  int a = 7;
  std::cout << a << std::endl;
  return 0;
}