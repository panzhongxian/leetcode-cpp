#include "0860_lemonade-change.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  vector<int> v1{5, 5, 5, 10, 20};
  EXPECT_EQ(s.lemonadeChange(v1), true);

  vector<int> v2{5, 5, 10, 10, 20};
  EXPECT_EQ(s.lemonadeChange(v2), false);

  vector<int> v3{5, 5, 10};
  EXPECT_EQ(s.lemonadeChange(v3), true);

  vector<int> v4{10, 10};
  EXPECT_EQ(s.lemonadeChange(v4), false);

  vector<int> v5{5, 5, 5, 10, 5, 5, 10, 20, 20, 20};
  EXPECT_EQ(s.lemonadeChange(v5), false);
}
