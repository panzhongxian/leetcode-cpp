#include "1466_reorder-routes-to-make-all-paths-lead-to-the-city-zero.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.minReorder(6, {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}}), 3);
  EXPECT_EQ(s.minReorder(5, {{1, 0}, {1, 2}, {3, 2}, {3, 4}}), 2);
  EXPECT_EQ(s.minReorder(3, {{1, 0}, {2, 0}}), 0);
}
