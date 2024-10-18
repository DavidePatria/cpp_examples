#include <print>

class Base {
public:
  Base() { std::println("constructing base"); };
  int id;
  int get_id() const { return id; }
};

class Derived : public Base {
public:
  Derived() { std::println("constructing derived"); };
};

int main(int argc, char *argv[]) {
  Derived derived;
  return 0;
}
