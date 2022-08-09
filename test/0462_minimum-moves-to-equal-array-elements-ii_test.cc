#include "0462_minimum-moves-to-equal-array-elements-ii.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  vector<int> v1{1, 2, 3};
  EXPECT_EQ(s.minMoves2(v1), 2);
  vector<int> v2{1, 0, 0, 8, 6};
  EXPECT_EQ(s.minMoves2(v2), 14);
  vector<int> v3{203125577, -349566234, 230332704,  48321315,   66379082,
                 386516853, 50986744,   -250908656, -425653504, -212123143};
  EXPECT_EQ(s.minMoves2(v3), 2127271182);
}
