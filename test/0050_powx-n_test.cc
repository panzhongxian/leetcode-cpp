#include "0050_powx-n.h"

#include "base.h"

TEST(S, Demo1) {
  Solution s;
  EXPECT_EQ(s.myPow(2, 10), 1024);
  EXPECT_EQ(s.myPow(2, 0), 1);
  EXPECT_EQ(s.myPow(2, -10), 1.0 / 1024);
}
