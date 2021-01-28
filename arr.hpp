#ifndef arr_hpp
#define arr_hpp

#include <iostream>

void fill_array(int* const arr, const int& size);

void print_array(const int* arr, const int& size);

void push_back(int*& arr, int& size, const int& element);

void pop_back(int*& arr, int& size);

template <typename T, std::size_t N>
std::size_t size(T (&)[N]) {
  return N;
}

#endif