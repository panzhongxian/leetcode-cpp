#include "0104_maximum-depth-of-binary-tree.h"

TEST(S, Demo) {
  Solution s;
  auto t1 = base::TreeNodeFactory<int>("[]");
  auto t2 = base::TreeNodeFactory<int>("[1,2,3]");
  auto t3 = base::TreeNodeFactory<int>("[1,2,3]");
  auto t4 = base::TreeNodeFactory<int>("[1,2]");
  auto t5 = base::TreeNodeFactory<int>("[1,null,2]");
  auto t6 = base::TreeNodeFactory<int>("[1,2,2,3,4,4,3]");
  auto t7 = base::TreeNodeFactory<int>("[1,2,2,null,3,null,3]");
  EXPECT_EQ(s.maxDepth(t1), 0);
  EXPECT_EQ(s.maxDepth(t2), 2);
  EXPECT_EQ(s.maxDepth(t4), 2);
  EXPECT_EQ(s.maxDepth(t5), 2);
  EXPECT_EQ(s.maxDepth(t6), 3);
  EXPECT_EQ(s.maxDepth(t7), 3);
}
