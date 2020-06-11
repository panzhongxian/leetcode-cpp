#include "0004_median-of-two-sorted-arrays.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.findMedianSortedArrays({1}, {}), 1);
  EXPECT_EQ(s.findMedianSortedArrays({1}, {2, 3}), 2.0);
  EXPECT_EQ(s.findMedianSortedArrays({1, 2}, {3}), 2.0);
  EXPECT_EQ(s.findMedianSortedArrays({1, 3}, {2}), 2.0);
  EXPECT_EQ(s.findMedianSortedArrays({1, 2}, {3, 4}), 2.5);
  EXPECT_EQ(s.findMedianSortedArrays({1, 2}, {-1, 3}), 1.5);
}
