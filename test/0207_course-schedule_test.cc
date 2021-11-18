#include "0207_course-schedule.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  vector<vector<int>> case1{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  EXPECT_EQ(s.canFinish(4, case1), true);

  vector<vector<int>> case2{{0, 1}, {1, 0}};
  EXPECT_EQ(s.canFinish(2, case2), false);

  vector<vector<int>> case3{{0, 1}};
  EXPECT_EQ(s.canFinish(2, case3), true);

  vector<vector<int>> case4{{0, 1}, {1, 2}, {2, 3}};
  EXPECT_EQ(s.canFinish(4, case4), true);

  vector<vector<int>> case5{{0, 1}, {1, 2}, {2, 3}, {3, 1}};
  EXPECT_EQ(s.canFinish(4, case5), false);
}
