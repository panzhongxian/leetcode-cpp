#include "0011_container_with_most_water.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.maxArea(vector<int>({1, 4, 2})), 2);
  EXPECT_EQ(s.maxArea(vector<int>({2, 4, 1})), 2);
  EXPECT_EQ(s.maxArea(vector<int>({2, 1})), 1);
  EXPECT_EQ(s.maxArea(vector<int>({1, 2})), 1);
  EXPECT_EQ(s.maxArea(vector<int>({1, 1})), 1);
  EXPECT_EQ(s.maxArea(vector<int>({1, 8, 6, 2, 5, 4, 8, 3, 7})), 49);
  EXPECT_EQ(s.maxArea(vector<int>({2, 3, 10, 5, 7, 8, 9})), 36);
  EXPECT_EQ(s.maxArea(vector<int>({2, 3, 4, 5, 18, 17, 6})), 17);
  EXPECT_EQ(s.maxArea(vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10})), 25);
}
