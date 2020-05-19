#include "base.h"
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int i = 0;
    int j = 0;
    int ret = 0;
    unordered_map<int, int> elem_idx;

    while (j < (int)s.length()) {
      if (!elem_idx.count(s[j]) || elem_idx[s[j]] == -1) {
        elem_idx[s[j]] = j;
        j++;
        continue;
      }

      ret = max(ret, j - i);
      int next_i = elem_idx[s[j]] + 1;
      for (; i < next_i; ++i) {
        s[i] = -1;
      }
      elem_idx[s[j]] = j;
      j++;
    }

    ret = max(ret, j - i);
    return ret;
  }
};

#if defined(LC_TEST)
TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring("abcba"), 3);
  EXPECT_EQ(s.lengthOfLongestSubstring("abcd"), 4);
  EXPECT_EQ(s.lengthOfLongestSubstring("abca"), 3);
  EXPECT_EQ(s.lengthOfLongestSubstring("aaaaa"), 1);
  EXPECT_EQ(s.lengthOfLongestSubstring("a"), 1);
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
