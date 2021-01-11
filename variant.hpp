#ifndef variant_hpp
#define variant_hpp

#include <iostream>
#include <variant>

// variant is simplier and safer than union.

class Not_union {
  std::variant<int, double> f;

 public:
  std::variant<int, double> get_variant() const { return f; }
  void set_variant(const int& i) { f = i; }
  void set_variant(const double& d) { f = d; }
  void print() {
    if (std::holds_alternative<int>(get_variant())) {
      std::cout << std::get<int>(get_variant()) << std::endl;
    } else {
      std::cout << std::get<double>(get_variant()) << std::endl;
    }
  }
};

#endif  // variant_hpp