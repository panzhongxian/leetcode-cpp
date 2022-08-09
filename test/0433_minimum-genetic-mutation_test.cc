#include "0433_minimum-genetic-mutation.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;

  EXPECT_EQ(s.minMutation("AACCGGTT", "AAACGGTA",
                          {"AACCGGTA", "AACCGCTA", "AAACGGTA"}),
            2);
}
