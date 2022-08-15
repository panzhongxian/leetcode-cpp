#include "1488_avoid-flood-in-the-city.h"

#include "base.h"
TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.avoidFlood({1, 2, 3, 4}), vector<int>({-1, -1, -1, -1}));
  EXPECT_EQ(s.avoidFlood({1, 2, 0, 0, 2, 1}),
            vector<int>({-1, -1, 2, 1, -1, -1}));
  EXPECT_EQ(s.avoidFlood({1, 2, 0, 1, 2}), vector<int>({}));
  EXPECT_EQ(s.avoidFlood({69, 0, 0, 0, 69}), vector<int>({-1, 69, 1, 1, -1}));
  EXPECT_EQ(s.avoidFlood({0, 1, 1}), vector<int>({}));
  EXPECT_EQ(s.avoidFlood({1, 0, 2, 0, 3, 0, 2, 0, 0, 0, 1, 2, 3}),
            vector<int>({-1, 1, -1, 2, -1, 3, -1, 2, 1, 1, -1, -1, -1}));
}
