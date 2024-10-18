
#include <ostream>
#include <string_view>
using namespace std::string_view_literals;
using namespace std::string_literals;

void stampa_vista(std::string_view view) { std::println("as sv: {}", view); };

void stampa_vista(std::string &view) { std::println("as s: {}", view); };

int main(int argc, char *argv[]) {
  auto normale = "stringa standard"s;
  auto vista = "vista stringa standard"sv;

  stampa_vista("normale"sv);
  stampa_vista(normale);
  stampa_vista(vista);

  return 0;
}
