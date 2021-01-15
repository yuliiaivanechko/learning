#ifndef vector_hpp
#define vector_hpp

#include <iostream>

template <class T>
class Vector {
  T *arr;
  int n;

 public:
  Vector();
  Vector(int num);
  Vector(const Vector &v);
  void fill();
  void operator=(const Vector<T> &v);
  T &operator[](int num) const;
  void display();
  int size() const;
  ~Vector();
};
template <class T>
Vector<T>::Vector() : arr(nullptr), n(0) {}

template <class T>
Vector<T>::Vector(int num) {
  if (num < 0) {
    throw std::length_error("Vector wrong length");
  }
  n = num;
  arr = new T[n]{};
}

template <class T>
Vector<T>::~Vector() {
  delete[] arr;
  arr = nullptr;
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
void Vector<T>::display() {
  for (int i = 0; i != n; ++i) std::cout << arr[i] << '\t';
  std::cout << std::endl;
}
#endif /* vector_hpp */