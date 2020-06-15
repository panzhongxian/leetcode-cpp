#include "0295_find-median-from-data-stream.h"

TEST(S, Demo1) {
  MedianFinder m;
  m.addNum(1);
  EXPECT_EQ(m.findMedian(), 1.0);
  m.addNum(2);
  EXPECT_EQ(m.findMedian(), 1.5);
  m.addNum(3);
  EXPECT_EQ(m.findMedian(), 2.0);
  m.addNum(4);
  EXPECT_EQ(m.findMedian(), 2.5);
}

TEST(S, Demo2) {
  MedianFinder m;
  m.addNum(-1);
  EXPECT_EQ(m.findMedian(), -1.0);
  m.addNum(-2);
  EXPECT_EQ(m.findMedian(), -1.5);
  m.addNum(-3);
  EXPECT_EQ(m.findMedian(), -2.0);
  m.addNum(-4);
  EXPECT_EQ(m.findMedian(), -2.5);
}
