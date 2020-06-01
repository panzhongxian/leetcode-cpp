#include "0091_decode-ways.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.numDecodings("0"), 0);
  EXPECT_EQ(s.numDecodings("10"), 1);
  EXPECT_EQ(s.numDecodings("120"), 1);
}
