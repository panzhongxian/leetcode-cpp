#include "0349_intersection-of-two-arrays.h"

#include "base.h"

TEST(S, Demo1) {
  Solution s;
  vector<int> v1{1, 2, 2, 1};
  vector<int> v2{2, 2};
  auto ret = s.intersection(v1, v2);
  sort(ret.begin(), ret.end());
  EXPECT_EQ(ret, vector<int>({2}));
}

TEST(S, Demo2) {
  Solution s;
  vector<int> v1{4, 9, 5};
  vector<int> v2{9, 4, 9, 8, 4};
  auto ret = s.intersection(v1, v2);
  sort(ret.begin(), ret.end());
  EXPECT_EQ(ret, vector<int>({4, 9}));
}
