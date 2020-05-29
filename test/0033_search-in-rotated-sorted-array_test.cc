#include "0033_search-in-rotated-sorted-array.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.searchMaxIdx(vector<int>({})), -1);
  EXPECT_EQ(s.searchMaxIdx(vector<int>({1})), 0);
  EXPECT_EQ(s.searchMaxIdx(vector<int>({1, 2})), 1);
  EXPECT_EQ(s.searchMaxIdx(vector<int>({2, 1})), 0);
  EXPECT_EQ(s.searchMaxIdx(vector<int>({3, 1, 2})), 0);
  EXPECT_EQ(s.searchMaxIdx(vector<int>({2, 3, 1})), 1);
  EXPECT_EQ(s.searchMaxIdx(vector<int>({1, 2, 3})), 2);

  EXPECT_EQ(s.search(vector<int>({}), 1), -1);
  EXPECT_EQ(s.search(vector<int>({1}), 1), 0);
  EXPECT_EQ(s.search(vector<int>({1, 2}), 1), 0);
  EXPECT_EQ(s.search(vector<int>({1, 2, 3}), 1), 0);
  EXPECT_EQ(s.search(vector<int>({1}), -1), -1);
  EXPECT_EQ(s.search(vector<int>({1, 2}), -1), -1);
  EXPECT_EQ(s.search(vector<int>({1, 2, 3}), -1), -1);
  EXPECT_EQ(s.search(vector<int>({1}), 0), -1);
  EXPECT_EQ(s.search(vector<int>({1, 2}), 0), -1);
  EXPECT_EQ(s.search(vector<int>({1, 2, 3}), 0), -1);
  EXPECT_EQ(s.search(vector<int>({1}), 2), -1);
  EXPECT_EQ(s.search(vector<int>({1, 2}), 2), 1);
  EXPECT_EQ(s.search(vector<int>({1, 2, 3}), 2), 1);

  EXPECT_EQ(s.search(vector<int>({3, 1, 2}), 4), -1);
  EXPECT_EQ(s.search(vector<int>({3, 1, 2}), -1), -1);
  EXPECT_EQ(s.search(vector<int>({3, 1, 2}), 1), 1);
  EXPECT_EQ(s.search(vector<int>({3, 1, 2}), 2), 2);
  EXPECT_EQ(s.search(vector<int>({3, 1, 2}), 3), 0);
}
