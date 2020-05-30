#include "0283_move-zeroes.h"

TEST(S, Demo) {
  Solution s;
  {
    vector<int> nums({1, 0});
    s.moveZeroes(nums);
    EXPECT_EQ(nums, vector<int>({1, 0}));
  }
  {
    vector<int> nums({0, 1});
    s.moveZeroes(nums);
    EXPECT_EQ(nums, vector<int>({1, 0}));
  }
  {
    vector<int> nums({0, 1, 0, 3, 12});
    s.moveZeroes(nums);
    EXPECT_EQ(nums, vector<int>({1, 3, 12, 0, 0}));
  }
}
