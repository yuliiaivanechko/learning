#ifndef vector_hpp
#define vector_hpp

#include <algorithm>
#include <initializer_list>

#include "container.hpp"

template <class T>
class Vector : public Container<T> {
  T *arr;
  int size;

 public:
  Vector();
  explicit Vector(int num);
  Vector(const Vector<T> &v);
  Vector(const std::initializer_list<T> &list);
  Vector(Vector<T> &&v);
  void fill();
  Vector<T> &operator=(const Vector<T> &v);
  Vector<T> &operator=(Vector<T> &&v);
  T &operator[](int num) const override;
  void display() const override;
  int size_() const override;
  ~Vector();
};
template <class T>
Vector<T>::Vector() : arr(nullptr), size(0) {}

template <class T>
Vector<T>::Vector(int num) {
  assert(num > 0);
  size = num;
  arr = new T[size]{};
}

template <class T>
Vector<T>::~Vector() {
  delete[] arr;
  arr = nullptr;
  std::cout << "Vector destructor" << std::endl;
}

template <class T>
Vector<T>::Vector(const std::initializer_list<T> &list)
    : size(list.size()), arr(new T[list.size()]) {
  std::copy(list.begin(), list.end(), arr);
}

template <class T>
Vector<T>::Vector(Vector<T> &&v) : arr(v.arr), size(v.size) {
  v.arr = nullptr;
  v.size = 0;
}

template <class T>
Vector<T>::Vector(const Vector<T> &v) {
  size = v.size;
  arr = new T[size];
  for (int i = 0; i != size; ++i) arr[i] = v.arr[i];
}

template <class T>
void Vector<T>::fill() {
  for (int i = 0; i != size; ++i) arr[i] = rand() % 30;
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &v) {
  T *new_vector = new T(v.size);
  for (int i = 0; i != v.size; ++i) {
    new_vector[i] = v.arr[i];
  }
  delete[] arr;
  arr = new_vector;
  size = v.size;
  return *this;
}

template <class T>
Vector<T> &Vector<T>::operator=(Vector<T> &&v) {
  arr = v.arr;
  size = v.size;
  v.arr = nullptr;
  v.size = 0;
  return *this;
}

template <class T>
int Vector<T>::size_() const {
  return size;
}

template <class T>
T &Vector<T>::operator[](int num) const {
  return arr[num];
}

template <class T>
void Vector<T>::display() const {
  for (int i = 0; i != size; ++i) std::cout << arr[i] << '\t';
  std::cout << std::endl;
}
#endif /* vector_hpp */