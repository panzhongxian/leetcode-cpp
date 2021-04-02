#include <inttypes.h>

#include <vector>
using namespace std;
class Solution {
 public:
  bool CheckSum(vector<int>& arr, size_t start, int64_t sum, size_t& end) {
    int cur_sum = 0;
    for (size_t i = start; i < arr.size(); i++) {
      cur_sum += arr[i];
      if (cur_sum == sum) {
        end = i;
        return true;
      }
    }
    return false;
  };

  bool canThreePartsEqualSum(vector<int>& arr) {
    if (arr.size() < 3) {
      return false;
    }
    int64_t sum = 0;
    for (int i : arr) {
      sum += i;
    }
    if (sum % 3) {
      return false;
    }
    sum /= 3;
    size_t end = 0;
    if (!CheckSum(arr, 0, sum, end)) {
      return false;
    }
    if (!CheckSum(arr, end + 1, sum, end)) {
      return false;
    }
    if (end == arr.size() - 1) {
      return false;
    }
    int64_t cur_sum = 0;
    for (int i = end + 1; i < arr.size(); ++i) {
      cur_sum += arr[i];
    }
    return cur_sum == sum;
  }
};
