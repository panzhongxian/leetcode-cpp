#include "0331_verify-preorder-serialization-of-a-binary-tree.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"), true);
  EXPECT_EQ(s.isValidSerialization("9,#"), false);
  EXPECT_EQ(s.isValidSerialization("9,#,#,1"), false);
  EXPECT_EQ(s.isValidSerialization("#"), true);
  EXPECT_EQ(s.isValidSerialization("1,#,#,#,#"), false);
  EXPECT_EQ(s.isValidSerialization("9,#,93,#,9,9,#,#,#"), true);
}
