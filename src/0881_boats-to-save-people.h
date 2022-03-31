#include <vector>
using std::vector;
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int right = people.size() - 1;
    int ret = 0;
    while (people[right] > limit) {
      ret++;
      right--;
      if (right < 0) {
        return ret;
      }
    }
    if (right == 0) {
      return ret + 1;
    }
    int left = 0;
    while (left <= right) {
      if (left == right) {
        return ret + 1;
      } else if (people[left] + people[right] <= limit) {
        left++;
      }
      right--;
      ret++;
    }
    return ret;
  }
};
