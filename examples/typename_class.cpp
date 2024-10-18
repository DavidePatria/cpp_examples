
// equivalent, but gives indication to the user about the expected types
#include <memory>
template <typename Type1, class Type2> void func(Type1, Type2) {}
// this works too
// template <typename Type1, typename Type2> void func(Type1, Type2) {}

int main() { // this works
  func(1, 3.2);
}

// here the class keyword is mandatory, only becasue inside a template template,
// since it is going to be a class inside there
// template <template <typename T, typename Alloc = std::allocator<T>>
//           class Container>
