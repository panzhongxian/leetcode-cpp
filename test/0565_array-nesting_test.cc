#include "0565_array-nesting.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  vector<int> v1{5, 4, 0, 3, 1, 6, 2};
  EXPECT_EQ(s.arrayNesting(v1), 4);
  vector<int> v2{1, 0, 2};
  EXPECT_EQ(s.arrayNesting(v2), 2);
  vector<int> v3{1, 2, 0};
  EXPECT_EQ(s.arrayNesting(v3), 3);
}
