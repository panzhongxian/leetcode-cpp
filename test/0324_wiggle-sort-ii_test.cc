#include "0324_wiggle-sort-ii.h"

TEST(S, Demo1) {
  Solution s;
  vector<int> v{};
  s.wiggleSort(v);
}

TEST(S, Demo2) {
  Solution s;
  vector<int> v{1};
  s.wiggleSort(v);
}

TEST(S, Demo3) {
  Solution s;
  vector<int> v{2, 1};
  s.wiggleSort(v);
}

TEST(S, Demo4) {
  Solution s;
  vector<int> v{1, 2, 3};
  s.wiggleSort(v);
  EXPECT_EQ(v, vector<int>({1, 3, 2}));
}
TEST(S, Demo5) {
  Solution s;
  vector<int> v{1, 2, 3, 4};
  s.wiggleSort(v);
  EXPECT_EQ(v, vector<int>({1, 3, 2, 4}));
}
TEST(S, Demo6) {
  Solution s;
  vector<int> v{1, 2, 3, 4, 5};
  s.wiggleSort(v);
  EXPECT_EQ(v, vector<int>({1, 4, 3, 5, 2}));
}

TEST(S, Demo7) {
  Solution s;
  vector<int> v{1, 1, 2, 1, 2, 2, 1};
  s.wiggleSort(v);
  EXPECT_EQ(v, vector<int>({1, 2, 1, 2, 1, 2, 1}));
}

TEST(S, Demo8) {
  Solution s;
  vector<int> v{1, 3, 2, 2, 3, 1};
  s.wiggleSort(v);
  cout << v << endl;
}
