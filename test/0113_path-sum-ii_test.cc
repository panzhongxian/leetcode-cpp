#include "0113_path-sum-ii.h"

typedef vector<vector<int>> vv_int;

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.pathSum(base::TreeNodeFactory<int>("[]"), 0), vv_int());
  EXPECT_EQ(s.pathSum(base::TreeNodeFactory<int>("[1]"), 1), vv_int({{1}}));
  EXPECT_EQ(s.pathSum(base::TreeNodeFactory<int>(
                          "[5,4,8,11,null,13,4,7,2,null,null,5,1]"),
                      22),
            vv_int({{5, 4, 11, 2}, {5, 8, 4, 5}}));
}
