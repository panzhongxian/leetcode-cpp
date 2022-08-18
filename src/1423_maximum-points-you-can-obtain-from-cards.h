#include <numeric>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxScore(const vector<int>& cardPoints, int k) {
    int curr_sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
    int ret = curr_sum;
    if (k == cardPoints.size()) {
      return ret;
    }
    int left = cardPoints.size() - 1;
    int right = k - 1;
    while (left >= cardPoints.size() - k) {
      curr_sum += cardPoints[left--] - cardPoints[right--];
      ret = max(ret, curr_sum);
    }
    return ret;
  }
};
