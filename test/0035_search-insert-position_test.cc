#include "0035_search-insert-position.h"

TEST(S, Demo) {
  Solution s;
  vector<int> v1({1, 3, 5, 7});
  EXPECT_EQ(s.searchInsert(v1, 0), 0);
  EXPECT_EQ(s.searchInsert(v1, 1), 0);
  EXPECT_EQ(s.searchInsert(v1, 2), 1);
  EXPECT_EQ(s.searchInsert(v1, 3), 1);
  EXPECT_EQ(s.searchInsert(v1, 5), 2);
  EXPECT_EQ(s.searchInsert(v1, 6), 3);
  EXPECT_EQ(s.searchInsert(v1, 7), 3);
  EXPECT_EQ(s.searchInsert(v1, 8), 4);
}
