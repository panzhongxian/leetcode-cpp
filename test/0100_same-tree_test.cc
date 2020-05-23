#include "0100_same-tree.h"

TEST(S, Demo) {
  Solution s;

  auto t1 = base::TreeNodeFactory<int>("[]");
  auto t2 = base::TreeNodeFactory<int>("[1,2,3]");
  auto t3 = base::TreeNodeFactory<int>("[1,2,3]");
  auto t4 = base::TreeNodeFactory<int>("[1,2]");
  auto t5 = base::TreeNodeFactory<int>("[1,null,2]");
  cout << t1 << endl;
  EXPECT_EQ(s.isSameTree(t1, nullptr), true);
  EXPECT_EQ(s.isSameTree(t2, t3), true);
  EXPECT_EQ(s.isSameTree(t1, t3), false);
  EXPECT_EQ(s.isSameTree(t2, t4), false);
  EXPECT_EQ(s.isSameTree(t2, t5), false);
}
