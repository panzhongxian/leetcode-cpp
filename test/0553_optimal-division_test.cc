#include "0553_optimal-division.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.optimalDivision({1000, 100, 10, 2}), "1000/(100/10/2)");
}
