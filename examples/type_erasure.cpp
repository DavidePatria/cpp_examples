#include <iostream>
#include <memory>
#include <print>

// =============================================================================
// ===================== TYPE ERASURE IMPLEMENTATION ===========================
// =============================================================================

// // interface for the types. to be accepted as a template a type as to be
// // compliant with this interface
// class AnimalConcept {
// public:
//   virtual const char *see() const = 0;
//   virtual const char *say() const = 0;
//   virtual ~AnimalConcept();
// };
//
// // wrapper for types
// template <typename T> class AnimalModel : public AnimalConcept {
//   const T *m_animal;
//
//   // wrapper class for external
// public:
//   AnimalModel(const T *animal) : m_animal(animal) {}
//
//   const char *see() const { return m_animal->see(); }
//   const char *say() const { return m_animal->say(); }
// };
//
// class SeeAndSay {
//
//   std::vector<std::unique_ptr<AnimalConcept>> m_animals;
//
// public:
//   template <typename T> void addAnimal(std::unique_ptr<T> animal) {
//     m_animals.emplace_back(animal);
//   }
//
//   void pullTheString() {
//     size_t index = rand() % m_animals.size();
//
//     // std::unique_ptr<AnimalConcept> animal = std::move(m_animals[index]);
//     auto &animal = m_animals[index];
//     std::cout << "The %s says '%s!'" << animal->see() << animal->say()
//               << std::endl;
//   }
// };
// //
// =============================================================================
//
// class Mucca {
// public:
//   void say() { std::cout << "sono una mucca" << '\n'; };
//   void see() { std::cout << "vedo una mucca" << '\n'; };
// };
//
// class Cavallo {
// public:
//   void say() { std::cout << "sono una mucca" << '\n'; };
// };
//
// int main(int argc, char *argv[]) {
//   SeeAndSay type;
//   std::unique_ptr<Mucca> muu = std::make_unique<Mucca>();
//   type.addAnimal(std::move(muu));
//   return 0;
// }

class AnimalConcept {
public:
  virtual std::string see() const = 0;
  virtual std::string say() const = 0;
};

template <typename T> class AnimalModel : public AnimalConcept {
  const T *m_animal;

public:
  AnimalModel(const T *animal) : m_animal(animal) {}

  std::string see() const { return m_animal->see(); }
  std::string say() const { return m_animal->say(); }
};

class SeeAndSay {

  std::vector<AnimalConcept *> m_animals;

public:
  template <typename T> void addAnimal(T *animal) {
    m_animals.push_back(new AnimalModel(animal));
  }

  void pullTheString() {
    size_t index = rand() % m_animals.size();

    AnimalConcept *animal = m_animals[index];
    std::println("The {} says '{}!'", animal->see(), animal->say());
  }
};

class Cow {
public:
  std::string see() const { return "muuu"; };
  std::string say() const { return "muuu"; };
};

int main(int argc, char *argv[]) {
  SeeAndSay say;
  Cow cow{};
  say.addAnimal(&cow);
  return 0;
}
