#ifndef BASE_NESTED_INTEGER_H_
#define BASE_NESTED_INTEGER_H_

#include <cassert>
#include <variant>
#include <vector>

class NestedInteger final {
 public:
  NestedInteger(int i) : value(i) {}
  NestedInteger(std::initializer_list<NestedInteger> ni) : value(ni) {}

  inline bool isInteger() const { return std::holds_alternative<int>(value); }
  inline int getInteger() const {
    assert(std::holds_alternative<int>(value));
    return std::get<int>(value);
  }

  inline const std::vector<NestedInteger>& getList() const {
    assert(std::holds_alternative<std::vector<NestedInteger>>(value));
    return std::get<std::vector<NestedInteger>>(value);
  }

 private:
  std::variant<int, std::vector<NestedInteger>> value;
};

#endif
