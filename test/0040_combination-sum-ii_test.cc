#include "0040_combination-sum-ii.h"
TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.combinationSum2({10, 1, 2, 7, 6, 1, 5}, 8).size(), 4);
  EXPECT_EQ(s.combinationSum2({2, 5, 2, 1, 2}, 5).size(), 2);
  ;
}
