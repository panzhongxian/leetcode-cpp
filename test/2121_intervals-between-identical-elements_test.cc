#include "2121_intervals-between-identical-elements.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.getDistances({2, 1, 3, 1, 2, 3, 3}),
            vector<long long>({4, 2, 7, 2, 4, 4, 5}));
}
