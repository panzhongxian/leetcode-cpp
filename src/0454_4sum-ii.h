#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> m1, m2;
    auto kk = [](vector<int>& v1, vector<int>& v2, unordered_map<int, int>& m) {
      int sum;
      for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
          sum = v1[i] + v2[j];
          m[sum]++;
        }
      }
    };
    kk(nums1, nums2, m1);
    kk(nums3, nums4, m2);
    int ret = 0;
    for (auto [k, v] : m1) {
      if (m2.find(-k) != m2.end()) {
        ret += v * m2[-k];
      }
    }
    return ret;
  }
};
