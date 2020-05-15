#include "base.h"
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> num_idx_mp;
    for (int i = 0; i < nums.size(); ++i) {
      int res = target - nums[i];
      if (num_idx_mp.count(res) > 0) {
        return vector<int>({num_idx_mp[res], i});
      }
      num_idx_mp[nums[i]] = i;
    }
    return vector<int>();
  }
};

#if defined(LC_TEST)
TEST(S, Demo) {
  Solution s;
  {
    vector<int> input = {1, 2, 3, 4};
    EXPECT_EQ(s.twoSum(input, 4), vector<int>({0, 2}));
  }
  {
    vector<int> input = {1, 2, 3, 4};
    EXPECT_EQ(s.twoSum(input, 9), vector<int>());
  }
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

#elif defined(LC_BM)

static void BM_S(benchmark::State &state) {
  for (auto _ : state) {
    Solution s;
    vector<int> input = {1, 2, 3, 4};
    EXPECT_EQ(s.twoSum(input, 4), vector<int>({0, 2}));
  }
}

BENCHMARK(BM_S);

BENCHMARK_MAIN();

#endif
