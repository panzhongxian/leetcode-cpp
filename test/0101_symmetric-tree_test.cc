#include "0101_symmetric-tree.h"

TEST(S, Demo) {
  Solution s;

  auto t1 = base::TreeNodeFactory<int>("[]");
  auto t2 = base::TreeNodeFactory<int>("[1,2,3]");
  auto t3 = base::TreeNodeFactory<int>("[1,2,3]");
  auto t4 = base::TreeNodeFactory<int>("[1,2]");
  auto t5 = base::TreeNodeFactory<int>("[1,null,2]");
  auto t6 = base::TreeNodeFactory<int>("[1,2,2,3,4,4,3]");
  auto t7 = base::TreeNodeFactory<int>("[1,2,2,null,3,null,3]");
  EXPECT_EQ(s.isSymmetric(t1), true);
  EXPECT_EQ(s.isSymmetric(t2), false);
  EXPECT_EQ(s.isSymmetric(t3), false);
  EXPECT_EQ(s.isSymmetric(t4), false);
  EXPECT_EQ(s.isSymmetric(t5), false);
  EXPECT_EQ(s.isSymmetric(t6), true);
  EXPECT_EQ(s.isSymmetric(t7), false);
}
