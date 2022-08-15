#include "1481_least-number-of-unique-integers-after-k-removals.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  vector<int> v1{5, 5, 4};
  EXPECT_EQ(s.findLeastNumOfUniqueInts(v1, 0), 2);
  EXPECT_EQ(s.findLeastNumOfUniqueInts(v1, 1), 1);
  EXPECT_EQ(s.findLeastNumOfUniqueInts(v1, 2), 1);
  EXPECT_EQ(s.findLeastNumOfUniqueInts(v1, 3), 0);
  vector<int> v2{4, 3, 1, 1, 3, 3, 2};
  EXPECT_EQ(s.findLeastNumOfUniqueInts(v2, 3), 2);
}
