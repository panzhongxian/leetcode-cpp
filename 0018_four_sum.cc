#include "base.h"

typedef unordered_map<int, vector<pair<int, int>>>::const_iterator umc_iter;
class Solution {
public:
  void insert_valid_quadruplet(const vector<int> &nums, set<vector<int>> &ret,
                               const vector<pair<int, int>> &v1,
                               const vector<pair<int, int>> &v2) {
    for (auto p1 : v1) {
      for (auto p2 : v2) {
        if (p1.first == p2.first || p1.first == p2.second ||
            p1.second == p2.first || p1.second == p2.second) {
          continue;
        }
        vector<int> tmp_vec(
            {nums[p1.first], nums[p1.second], nums[p2.first], nums[p2.second]});
        sort(tmp_vec.begin(), tmp_vec.end());
        ret.insert(move(tmp_vec));
      }
    }
  }

  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> ret;
    set<vector<int>> ret_set;
    sort(nums.begin(), nums.end());

    unordered_map<int, vector<pair<int, int>>> pair_sum_mp;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        pair_sum_mp[nums[i] + nums[j]].push_back(pair<int, int>({i, j}));
      }
    }

    for (umc_iter iter1 = pair_sum_mp.begin(); iter1 != pair_sum_mp.end();
         ++iter1) {
      umc_iter iter2 = pair_sum_mp.find(target - iter1->first);
      if (iter2 == pair_sum_mp.end())
        continue;

      // TODO: stop if passed.
      // if (iter2 < iter1)
      //   break;

      insert_valid_quadruplet(nums, ret_set, iter1->second, iter2->second);
    }

    for (auto elem : ret_set) {
      ret.push_back(move(elem));
    }
    return ret;
  }
};

#if defined(LC_TEST)
TEST(S, Demo) {
  Solution s;
  vector<int> input({1, 0, -1, 0, -2, 2});
  s.fourSum(input, 0);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

#elif defined(LC_BM)

static void BM_S(benchmark::State &state) {
  for (auto _ : state) {
    // Solution s;
    // execute s.Solve
  }
}

BENCHMARK(BM_S);

BENCHMARK_MAIN();

#endif
