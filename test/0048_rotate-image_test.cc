#include "0048_rotate-image.h"

#include "base.h"

using namespace base;

TEST(S, Demo) {
  Solution s;

  {
    vector<vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotate(v);
  }
  {
    vector<vector<int>> v{
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    s.rotate(v);
  }
}
