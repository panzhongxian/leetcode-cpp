#include "0098_validate-binary-search-tree.h"

TEST(S, Demo) {
  Solution s;

  EXPECT_EQ(s.isValidBST(base::TreeNodeFactory<int>("[]")), true);
  EXPECT_EQ(s.isValidBST(base::TreeNodeFactory<int>("[1]")), true);
  EXPECT_EQ(s.isValidBST(base::TreeNodeFactory<int>("[1,1]")), false);
  EXPECT_EQ(s.isValidBST(base::TreeNodeFactory<int>("[1,2]")), false);
  EXPECT_EQ(s.isValidBST(base::TreeNodeFactory<int>("[1,null,2]")), true);
  EXPECT_EQ(s.isValidBST(base::TreeNodeFactory<int>("[2,1,3]")), true);
  EXPECT_EQ(s.isValidBST(base::TreeNodeFactory<int>("[1,2,3]")), false);
  EXPECT_EQ(s.isValidBST(base::TreeNodeFactory<int>("[3,1,2]")), false);
  EXPECT_EQ(s.isValidBST(base::TreeNodeFactory<int>("[5,14,null, 1]")), false);
  EXPECT_EQ(s.isValidBST(base::TreeNodeFactory<int>("[5,1,4,null,null,3,6]")),
            false);
  EXPECT_EQ(
      s.isValidBST(base::TreeNodeFactory<int>("[10,5,15,null,null,6,20]")),
      false);
}
