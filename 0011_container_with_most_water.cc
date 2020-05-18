#include "base.h"
class Solution {
public:
  /*
   * https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
   * https://zhuanlan.zhihu.com/p/33737430
   */

  int calcCapacity(const vector<int> &height, int i, int j) {
    assert(j >= i);
    return (j - i) * min(height[i], height[j]);
  }

  int maxArea(const vector<int> &height) {

    int i, j;
    i = 0;
    j = height.size() - 1;
    int ret = 0;

    while (i < j) {
      ret = max(calcCapacity(height, i, j), ret);
      if (height[i] < height[j]) {
        i++;
      } else {
        j--;
      }
    }
    return ret;
  }
};

#if defined(LC_TEST)
TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.maxArea(vector<int>({1, 4, 2})), 2);
  EXPECT_EQ(s.maxArea(vector<int>({2, 4, 1})), 2);
  EXPECT_EQ(s.maxArea(vector<int>({2, 1})), 1);
  EXPECT_EQ(s.maxArea(vector<int>({1, 2})), 1);
  EXPECT_EQ(s.maxArea(vector<int>({1, 1})), 1);
  EXPECT_EQ(s.maxArea(vector<int>({1, 8, 6, 2, 5, 4, 8, 3, 7})), 49);
  EXPECT_EQ(s.maxArea(vector<int>({2, 3, 10, 5, 7, 8, 9})), 36);
  EXPECT_EQ(s.maxArea(vector<int>({2, 3, 4, 5, 18, 17, 6})), 17);
  EXPECT_EQ(s.maxArea(vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10})), 25);
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
