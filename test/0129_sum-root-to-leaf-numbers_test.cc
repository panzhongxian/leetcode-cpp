#include "0129_sum-root-to-leaf-numbers.h"

typedef vector<vector<int>> vv_int;

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.sumNumbers(base::TreeNodeFactory<int>("[]")), 0);
  EXPECT_EQ(s.sumNumbers(base::TreeNodeFactory<int>("[1]")), 1);
  EXPECT_EQ(s.sumNumbers(base::TreeNodeFactory<int>("[4,9,0,5,1]")), 1026);
  EXPECT_EQ(s.sumNumbers(base::TreeNodeFactory<int>("[1,2,3]")), 25);
}
