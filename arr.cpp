#include "arr.hpp"

#include <iostream>

void fill_array(int* const arr, const int& size) {
  assert(size >= 0);
  for (std::size_t i = 0; i != size; ++i) {
    arr[i] = rand() % 30;
  }
}

void print_array(const int const* arr, const int& size) {
  for (std::size_t i = 0; i != size; ++i) {
    std::cout << arr[i] << "\t";
  }
  std::cout << std::endl;
}

void push_back(int*& arr, int& size, const int& element) {
  int* new_arr = new int[size + 1];
  for (std::size_t i = 0; i != size; ++i) {
    new_arr[i] = arr[i];
  }
  new_arr[size++] = element;
  delete[] arr;
  arr = new_arr;
}

void pop_back(int*& arr, int& size) {
  int* new_arr = new int[size - 1];
  for (std::size_t i = 0; i != size - 1; ++i) {
    new_arr[i] = arr[i];
  }
  delete arr;
  size--;
  arr = new_arr;
}