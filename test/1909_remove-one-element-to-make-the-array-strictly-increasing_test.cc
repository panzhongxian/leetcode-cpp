#include "1909_remove-one-element-to-make-the-array-strictly-increasing.h"

TEST(Solution, s) {
  Solution s;
  vector<int> v1{1, 2, 3};
  EXPECT_TRUE(s.canBeIncreasing(v1));

  vector<int> v2{6, 562, 624, 803, 747, 981, 841};
  EXPECT_FALSE(s.canBeIncreasing(v2));
}
