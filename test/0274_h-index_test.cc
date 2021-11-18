#include "0274_h-index.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  vector<int> v1{0, 0, 4, 4};
  EXPECT_EQ(s.hIndex(v1), 2);
  vector<int> v2{4, 4, 4, 4};
  EXPECT_EQ(s.hIndex(v2), 4);
  vector<int> v3{1, 2, 3, 4};
  EXPECT_EQ(s.hIndex(v3), 2);
  vector<int> v4{10, 10, 14, 14};
  EXPECT_EQ(s.hIndex(v4), 4);
}
