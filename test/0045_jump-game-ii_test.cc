#include "0045_jump-game-ii.h"

#include "base.h"

using namespace base;

TEST(S, Demo) {
  Solution s;

  {
    vector<int> nums{2, 3, 1, 1, 4};
    ASSERT_EQ(s.jump(nums), 2);
  }
  {
    vector<int> nums{2, 3, 0, 1, 4};
    ASSERT_EQ(s.jump(nums), 2);
  }
}
