#include "0112_path-sum.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.hasPathSum(base::TreeNodeFactory<int>("[]"), 0), false);
  EXPECT_EQ(s.hasPathSum(base::TreeNodeFactory<int>("[1]"), 1), true);
  EXPECT_EQ(
      s.hasPathSum(base::TreeNodeFactory<int>("[1,2,2,3,3,null,null,4,5]"), 10),
      true);
  EXPECT_EQ(
      s.hasPathSum(base::TreeNodeFactory<int>("[1,2,2,3,3,null,null,4,5]"), 11),
      true);
  EXPECT_EQ(
      s.hasPathSum(base::TreeNodeFactory<int>("[1,2,2,3,3,null,null,4,5]"), 12),
      false);
}
