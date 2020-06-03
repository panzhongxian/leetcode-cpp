#include "0088_merge-sorted-array.h"

TEST(S, Demo1) {
  Solution s;
  vector<int> v1{1, 2, 3, 0, 0, 0}, v2{2, 5, 6};
  s.merge(v1, 3, v2, 3);
  EXPECT_EQ(v1, vector<int>({1, 2, 2, 3, 5, 6}));
}

TEST(S, Demo2) {
  Solution s;
  vector<int> v1{1, 2, 3, 0, 0, 0}, v2{2, 5, 6};
  s.merge(v1, 0, v2, 3);
  EXPECT_EQ(v1, vector<int>({2, 5, 6, 0, 0, 0}));
}

TEST(S, Demo3) {
  Solution s;
  vector<int> v1{2, 0}, v2{1};
  s.merge(v1, 1, v2, 1);
  EXPECT_EQ(v1, vector<int>({1, 2}));
}
