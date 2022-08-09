#include "2335_minimum-amount-of-time-to-fill-cups.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  vector<int> v1{3, 4, 3};
  EXPECT_EQ(s.fillCups(v1), 5);

  vector<int> v2{4, 4, 5};
  EXPECT_EQ(s.fillCups(v2), 7);

  vector<int> v3{4, 4, 9};
  EXPECT_EQ(s.fillCups(v3), 9);

  vector<int> v4{1, 1, 1};
  EXPECT_EQ(s.fillCups(v4), 2);

  vector<int> v5{3, 4, 4};
  EXPECT_EQ(s.fillCups(v5), 6);

  vector<int> v6{3, 2, 4};
  EXPECT_EQ(s.fillCups(v6), 5);
}
