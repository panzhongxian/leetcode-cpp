#include "0102_binary-tree-level-order-traversal.h"

TEST(S, Demo) {
  Solution s;
  auto t1 = base::TreeNodeFactory<int>("[]");
  auto t2 = base::TreeNodeFactory<int>("[1,2,3]");
  auto t3 = base::TreeNodeFactory<int>("[1,2,3]");
  auto t4 = base::TreeNodeFactory<int>("[1,2]");
  auto t5 = base::TreeNodeFactory<int>("[1,null,2]");
  auto t6 = base::TreeNodeFactory<int>("[1,2,2,3,4,4,3]");
  auto t7 = base::TreeNodeFactory<int>("[1,2,2,null,3,null,3]");
  EXPECT_EQ(s.levelOrder(t1), vector<vector<int>>({}));
  EXPECT_EQ(s.levelOrder(t2), vector<vector<int>>({{1}, {2, 3}}));
  EXPECT_EQ(s.levelOrder(t4), vector<vector<int>>({{1}, {2}}));
  EXPECT_EQ(s.levelOrder(t5), vector<vector<int>>({{1}, {2}}));
  EXPECT_EQ(s.levelOrder(t6), vector<vector<int>>({{1}, {2, 2}, {3, 4, 4, 3}}));
  EXPECT_EQ(s.levelOrder(t7), vector<vector<int>>({{1}, {2, 2}, {3, 3}}));
}
