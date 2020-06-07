#include "0437_path-sum-iii.h"

TEST(S, Demo) {
  Solution s;
  // EXPECT_EQ(s.pathSum(base::TreeNodeFactory<int>("[]"), 0), 0);
  // EXPECT_EQ(s.pathSum(base::TreeNodeFactory<int>("[1]"), 1), 1);
  EXPECT_EQ(
      s.pathSum(base::TreeNodeFactory<int>("[10,5,-3,3,2,null,11,3,-2,null,1]"),
                8),
      3);
}
