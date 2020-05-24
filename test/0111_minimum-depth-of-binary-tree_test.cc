#include "0111_minimum-depth-of-binary-tree.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.minDepth(base::TreeNodeFactory<int>("[]")), 0);
  EXPECT_EQ(s.minDepth(base::TreeNodeFactory<int>("[1]")), 1);
  EXPECT_EQ(s.minDepth(base::TreeNodeFactory<int>("[1,2,2]")), 2);
  EXPECT_EQ(s.minDepth(base::TreeNodeFactory<int>("[1,null,2]")), 2);
  EXPECT_EQ(s.minDepth(base::TreeNodeFactory<int>("[1,2,null]")), 2);
  EXPECT_EQ(s.minDepth(base::TreeNodeFactory<int>("[3,9,20,null,null,15,7]")),
            2);
  EXPECT_EQ(s.minDepth(base::TreeNodeFactory<int>("[1,2,2,3,3,null,null,4,4]")),
            2);
}
