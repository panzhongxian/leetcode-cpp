#include "base.h"

const int max_palindrome = 2147447412;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (!x) return true;
    if (x < 0 || x % 10 == 0) return false;
    int left = x;
    int right = 0;
    while (left > right) {
      right = right * 10 + left % 10;
      left = left / 10;
    }
    return left == right || abs(right - left * 10) < 10;
  }
};

#if defined(LC_TEST)
TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.isPalindrome(0), true);
  EXPECT_EQ(s.isPalindrome(2147483642), false);
  EXPECT_EQ(s.isPalindrome(-2147483642), false);
  EXPECT_EQ(s.isPalindrome(2147447412), true);
  EXPECT_EQ(s.isPalindrome(1234), false);
  EXPECT_EQ(s.isPalindrome(1234321), true);
  EXPECT_EQ(s.isPalindrome(12344321), true);
  EXPECT_EQ(s.isPalindrome(10), false);
  EXPECT_EQ(s.isPalindrome(100), false);
  EXPECT_EQ(s.isPalindrome(1000), false);
  EXPECT_EQ(s.isPalindrome(1001), true);
  EXPECT_EQ(s.isPalindrome(10001), true);
  // execute s.Solve
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

#elif defined(LC_BM)

static void BM_S(benchmark::State &state) {
  for (auto _ : state) {
    Solution s;
    // execute s.Solve
  }
}

BENCHMARK(BM_S);

BENCHMARK_MAIN();

#endif
