#include "0215_kth-largest-element-in-an-array.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.findKthLargest({3, 2, 1, 5, 6, 4}, 2), 5);
  EXPECT_EQ(s.findKthLargest({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4), 4);
}
