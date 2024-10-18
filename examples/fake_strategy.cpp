
#include <algorithm>
#include <memory>
#include <numeric>
#include <print>
#include <vector>

// template that takes a functor and uses it on a container
template <typename T, class Functor>
void revert(T &container, Functor &&functor) {
  std::for_each(std::begin(container), std::end(container),
                [&container, &functor](auto &el) { functor(el); });
  std::println("");
};

// maybe template is useless, but here the function simply increments the
// argument by one
class MyFunction {
public:
  template <typename T> void operator()(T &element) {
    ++element;
    std::print("{} ", element);
  };
};

// =========================
template <class T> class Operation {
  // takes a functor and assigns it to the internal pointer
public:
  Operation(std::unique_ptr<T> functor) { operation = std::move(functor); };
  std::unique_ptr<T> operation;
  template <typename Cont> void operate(Cont container) {
    (*operation)(container);
  };
};

int main(int argc, char *argv[]) {

  std::vector<int> un_vettore(5, 0);
  std::println("{}", un_vettore);
  std::iota(un_vettore.begin(), un_vettore.end(), 0);
  std::println("{}", un_vettore);

  revert(un_vettore, MyFunction{});
  std::println("{}", un_vettore);

  // ===============
  auto op_pt = std::make_unique<MyFunction>(MyFunction{});
  Operation op(std::move(op_pt));
  op.operate(un_vettore);
  std::println("{}", un_vettore);

  return 0;
}
