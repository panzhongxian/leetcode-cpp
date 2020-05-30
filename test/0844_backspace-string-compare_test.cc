#include "0844_backspace-string-compare.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.backspaceCompare("ab#c", "ad#c"), true);
  EXPECT_EQ(s.backspaceCompare("ab##", "a#d#"), true);
  EXPECT_EQ(s.backspaceCompare("a##c", "#a#c"), true);
  EXPECT_EQ(s.backspaceCompare("a#c", "b"), false);
}
