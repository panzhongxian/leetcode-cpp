#include <cstring>
#include <vector>
using namespace std;
class Solution {
 public:
  int findJudge(int N, vector<vector<int>>& trust) {
    int trusted_cnt[N + 1];
    int trust_other_flag[N + 1];
    memset(trusted_cnt, 0, sizeof(int) * (N + 1));
    memset(trust_other_flag, 0, sizeof(int) * (N + 1));
    for (auto& a : trust) {
      trust_other_flag[a[0]] = 1;
      trusted_cnt[a[1]] += 1;
    }
    vector<int> judge_vec;
    for (int i = 1; i <= N; i++) {
      if (!trust_other_flag[i] && trusted_cnt[i] == N - 1) {
        judge_vec.push_back(i);
      }
    }
    if (judge_vec.size() == 1) {
      return judge_vec[0];
    }
    return -1;
  }
};
