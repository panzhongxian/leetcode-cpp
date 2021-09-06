#include "0080_remove-duplicates-from-sorted-array-ii.h"

#include "base.h"

TEST(S, Demo1) {
  Solution s;
  vector<int> v{1, 1, 1, 2, 2, 3};
  int ret = s.removeDuplicates(v);
  EXPECT_EQ(ret, 5);
  vector<int> ret_vec(v.begin(), v.begin() + 5);
  vector<int> expect_vec{1, 1, 2, 2, 3};
  EXPECT_EQ(ret_vec, expect_vec);
}

TEST(S, Demo2) {
  Solution s;
  vector<int> v{0, 0, 1, 1, 1, 1, 2, 3, 3};
  int ret = s.removeDuplicates(v);
  EXPECT_EQ(ret, 7);
  vector<int> ret_vec(v.begin(), v.begin() + 7);
  vector<int> expect_vec{0, 0, 1, 1, 2, 3, 3};
  EXPECT_EQ(ret_vec, expect_vec);
}
