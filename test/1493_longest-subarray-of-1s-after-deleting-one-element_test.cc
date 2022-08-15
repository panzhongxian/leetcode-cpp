#include "1493_longest-subarray-of-1s-after-deleting-one-element.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.longestSubarray({1, 1, 0, 1}), 3);
  EXPECT_EQ(s.longestSubarray({0, 1, 1, 1, 0, 1, 1, 0, 1}), 5);
  EXPECT_EQ(s.longestSubarray({1, 1, 1}), 2);
}
