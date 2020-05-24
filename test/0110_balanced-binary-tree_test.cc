#include "0110_balanced-binary-tree.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.isBalanced(base::TreeNodeFactory<int>("[]")), true);
  EXPECT_EQ(s.isBalanced(base::TreeNodeFactory<int>("[1]")), true);
  EXPECT_EQ(s.isBalanced(base::TreeNodeFactory<int>("[1,2,2]")), true);
  EXPECT_EQ(s.isBalanced(base::TreeNodeFactory<int>("[1,null,2]")), true);
  EXPECT_EQ(s.isBalanced(base::TreeNodeFactory<int>("[1,2,null]")), true);
  EXPECT_EQ(s.isBalanced(base::TreeNodeFactory<int>("[3,9,20,null,null,15,7]")),
            true);
  EXPECT_EQ(
      s.isBalanced(base::TreeNodeFactory<int>("[1,2,2,3,3,null,null,4,4]")),
      false);
}
