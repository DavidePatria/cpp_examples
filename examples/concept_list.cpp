#include <concepts>
#include <iostream>
#include <type_traits>

// Alias per i tipi consentiti
using AllowedTypes = std::tuple<int, double, float>;

// Concept compatto che verifica se T è uno dei tipi nell'alias AllowedTypes
template <typename T>
concept AllowedType = std::disjunction_v<
    std::is_same<T, std::tuple_element_t<I, AllowedTypes>>...>;

// Funzione template abilitata solo per i tipi consentiti
template <AllowedType T> void func(T value) {
  std::cout << "Valore: " << value << '\n';
}

int main() {
  func(42);    // OK, int è permesso
  func(3.14);  // OK, double è permesso
  func(2.71f); // OK, float è permesso

  // func("test"); // ERRORE: il tipo const char* non è permesso
}
