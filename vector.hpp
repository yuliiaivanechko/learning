#ifndef vector_hpp
#define vector_hpp

#include <algorithm>
#include <initializer_list>

#include "container.hpp"

template <class T>
class Vector : public Container<T> {
  T *arr;
  int n;

 public:
  Vector();
  explicit Vector(int num);
  Vector(const Vector &v);
  Vector(const std::initializer_list<T> &list);
  void fill();
  void operator=(const Vector<T> &v);
  T &operator[](int num) const override;
  void display() const override;
  int size() const override;
  ~Vector();
};
template <class T>
Vector<T>::Vector() : arr(nullptr), n(0) {}

template <class T>
Vector<T>::Vector(int num) {
  assert(num > 0);
  n = num;
  arr = new T[n]{};
}

template <class T>
Vector<T>::~Vector() {
  delete[] arr;
  arr = nullptr;
  std::cout << "Vector destructor" << std::endl;
}

template <class T>
Vector<T>::Vector(const std::initializer_list<T> &list)
    : n(list.size()), arr(new T[list.size()]) {
  std::copy(list.begin(), list.end(), arr);
}

template <class T>
Vector<T>::Vector(const Vector<T> &v) {
  n = v.n;
  arr = new T[n];
  for (int i = 0; i != n; ++i) arr[i] = v.arr[i];
}

template <class T>
void Vector<T>::fill() {
  for (int i = 0; i != n; ++i) arr[i] = rand() % 30;
}

template <class T>
void Vector<T>::operator=(const Vector<T> &v) {
  if (n != v.n) {
    delete[] arr;
    n = v.n;
    arr = new T[n];
    for (int i = 0; i != n; ++i) arr[i] = v.arr[i];
  } else {
    for (int i = 0; i != n; ++i) arr[i] = v.arr[i];
  }
}

template <class T>
int Vector<T>::size() const {
  return n;
}

template <class T>
T &Vector<T>::operator[](int num) const {
  return arr[num];
}

template <class T>
void Vector<T>::display() const {
  for (int i = 0; i != n; ++i) std::cout << arr[i] << '\t';
  std::cout << std::endl;
}
#endif /* vector_hpp */