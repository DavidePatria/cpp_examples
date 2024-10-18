#include <cstdio>
#include <memory>
#include <print>
#include <vector>

struct Puntero {
  std::unique_ptr<int> puntero;
};

struct Prova {
  int mio;
  int tuo;
  std::unique_ptr<int> mosso_1;
  std::unique_ptr<int> mosso_2;
  Puntero puntero;
};

void moving_ptr(std::unique_ptr<Prova> &&ptr,
                std::vector<std::unique_ptr<Prova>> &vec) {
  vec.push_back(std::move(ptr));
};

int main(int argc, char *argv[]) {
  auto prova = std::make_unique<Prova>(1, 2, std::make_unique<int>(3),
                                       std::make_unique<int>(4));
  // unexpected after move
  std::println("{}", prova->mio, prova->tuo);

  auto altro{std::move(prova)};

  // unexpected after move
  std::println("{}, {}, {}", altro->mio, altro->tuo, *altro->mosso_1);

  // // unexpected after move
  // std::println("{}", prova->mio);

  Prova spostanda{10, 20, std::make_unique<int>(30), std::make_unique<int>(40)};
  std::println("{}, {}, {}", spostanda.mio, spostanda.tuo,
               *(spostanda.mosso_1));

  Prova spostata = std::move(spostanda);
  std::println("{}, {}, {}", spostata.mio, spostata.tuo, *(spostata.mosso_1));

  // let's try pushing inside a vector of ptrs
  std::vector<std::unique_ptr<Prova>> vec;
  auto my_ptr = std::make_unique<Prova>();
  // to be pushed this needs a move
  vec.push_back(std::move(my_ptr));

  auto another_ptr = std::make_unique<Prova>();
  moving_ptr(std::move(another_ptr), vec);

  std::println("size of vector after all operations: {}", vec.size());

  return 0;
}
