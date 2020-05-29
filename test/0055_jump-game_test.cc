#include "0055_jump-game.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.canJump(vector<int>(10000, 1)), true);
  EXPECT_EQ(s.canJump(vector<int>({2})), true);
  EXPECT_EQ(s.canJump(vector<int>({2, 3, 1, 1, 4})), true);
  EXPECT_EQ(s.canJump(vector<int>({3, 2, 1, 0, 4})), false);
}
