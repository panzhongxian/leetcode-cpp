#include "1656_design-an-ordered-stream.h"

#include "base.h"

TEST(Solution, Demo) {
  OrderedStream s(5);
  s.insert(3, "c");
  s.insert(1, "a");
  s.insert(2, "b");
  s.insert(5, "e");
  s.insert(4, "d");
}
