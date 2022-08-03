#include "0503_next-greater-element-ii.h"

#include "base.h"
TEST(S, Demo1) {
  vector<int> v{1, 2, 3, 4, 5};
  Solution s;
  vector<int> expect{2, 3, 4, 5, -1};
  EXPECT_EQ(s.nextGreaterElements(v), expect);
}

TEST(S, Demo2) {
  vector<int> v{5, 4, 3, 2, 1};
  Solution s;
  vector<int> expect{-1, 5, 5, 5, 5};
  EXPECT_EQ(s.nextGreaterElements(v), expect);
}
