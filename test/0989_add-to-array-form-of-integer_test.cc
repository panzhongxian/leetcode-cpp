#include "0989_add-to-array-form-of-integer.h"

#include "base.h"

TEST(S2, Demo) {
  Solution2 s;
  vector<int> A{1, 2, 0, 0};
  s.addToArrayForm(A, 34);
  EXPECT_EQ(A, vector<int>({1, 2, 3, 4}));

  A = {0};
  s.addToArrayForm(A, 10000);
  EXPECT_EQ(A, vector<int>({1, 0, 0, 0, 0}));
}
