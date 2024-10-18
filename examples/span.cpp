#include <array>
#include <iostream>
#include <print>
#include <span>
#include <vector>

void spam_span(const std::span<int> &printing) {
  std::println("{}", printing);
};

int main(int argc, char *argv[]) {
  std::vector<int> vec(4, 1);
  std::println("{}", vec);

  std::span<int> span{vec};

  spam_span(span);
  // std::cout << span << '\n';
  // std::println("{}", span);

  return 0;
}
