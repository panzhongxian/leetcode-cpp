#include "0015_three-sum.h"

TEST(S, Demo1) {
  Solution s;
  vector<int> p = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = s.threeSum(p);
  EXPECT_EQ(set<vector<int>>(result.begin(), result.end()), set<vector<int>>({
                                                                {-1, 0, 1},
                                                                {-1, -1, 2},
                                                            }));
}

TEST(S, Demo2) {
  Solution s;
  vector<int> p = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  vector<vector<int>> result = s.threeSum(p);
  EXPECT_EQ(set<vector<int>>(result.begin(), result.end()),
            set<vector<int>>({{-4, -2, 6},
                              {-4, 0, 4},
                              {-4, 1, 3},
                              {-4, 2, 2},
                              {-2, -2, 4},
                              {-2, 0, 2}}));
}
