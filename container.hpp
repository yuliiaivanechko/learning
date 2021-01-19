#ifndef container_hpp
#define container_hpp

template <class T>
class Container {
 public:
  virtual T& operator[](int) const = 0;
  virtual int size() const = 0;
  virtual ~Container() {}
  virtual void display() const = 0;
};

#endif