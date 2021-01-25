#ifndef container_hpp
#define container_hpp
#include <iostream>

template <class T>
class Container {
 public:
  virtual T& operator[](int) const = 0;
  virtual int size_() const = 0;
  virtual ~Container() { std::cout << "Destructor container" << std::endl; }
  virtual void display() const = 0;
};

#endif