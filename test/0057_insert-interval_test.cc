#include "0057_insert-interval.h"

#include "base.h"

using namespace base;
TEST(S, Demo1) {
  Solution s;
  vector<vector<int>> intervals{{1, 3}, {6, 9}};
  vector<int> newInterval{2, 5};
  auto ret = s.insert(intervals, newInterval);
  vector<vector<int>> expected_ret{{1, 5}, {6, 9}};
  EXPECT_EQ(ret, expected_ret);
}
TEST(S, Demo2) {
  Solution s;
  vector<vector<int>> intervals{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval{4, 8};
  auto ret = s.insert(intervals, newInterval);
  vector<vector<int>> expected_ret{{1, 2}, {3, 10}, {12, 16}};
  EXPECT_EQ(ret, expected_ret);
}
TEST(S, Demo3) {
  Solution s;
  vector<vector<int>> intervals{};
  vector<int> newInterval{5, 7};
  auto ret = s.insert(intervals, newInterval);
  vector<vector<int>> expected_ret{{5, 7}};
  EXPECT_EQ(ret, expected_ret);
}
