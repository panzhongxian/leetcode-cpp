#include "0556_next-greater-element-iii.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.nextGreaterElement(103210), 110023);
  EXPECT_EQ(s.nextGreaterElement(210), -1);
  EXPECT_EQ(s.nextGreaterElement(120), 201);
  EXPECT_EQ(s.nextGreaterElement(2147483486), -1);
}
