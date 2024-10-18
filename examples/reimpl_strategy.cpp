#include <iostream>
#include <memory>
#include <print>
#include <string>

class Strategy {

public:
  virtual void print_to_screen(std::string data) = 0;
  virtual ~Strategy() = default;
};

class Context {
public:
  std::unique_ptr<Strategy> operation;
  explicit Context(std::unique_ptr<Strategy> &&strategy = {},
                   std::string data = "")
      : operation(std::move(strategy)), data_(data){};

  void print() { operation->print_to_screen(data_); };

private:
  std::string data_;
};

class printStrategy : public Strategy {
  void print_to_screen(std::string data) { std::println("{}", data); };
};

class coutStrategy : public Strategy {
  void print_to_screen(std::string data) { std::cout << data << '\n'; };
};

int main(int argc, char *argv[]) {
  Context contesto(std::make_unique<printStrategy>(), "vediamo");
  contesto.print();

  return 0;
}
