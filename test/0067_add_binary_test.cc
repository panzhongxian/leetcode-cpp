#include "0067_add_binary.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.addBinary("1", "11"), "100");
  EXPECT_EQ(s.addBinary("", "1111"), "1111");
  EXPECT_EQ(s.addBinary("11", "1"), "100");
  EXPECT_EQ(s.addBinary("1111", ""), "1111");
  EXPECT_EQ(s.addBinary("1010", "1011"), "10101");
}
