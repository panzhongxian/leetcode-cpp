class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    if (numbers.size() == 0) {
      return {};
    }

    int left = 0;
    int right = numbers.size() - 1;
    int tmp_sum;
    while (left < right) {
      int tmp_sum = numbers[left] + numbers[right];
      if (tmp_sum == target) {
        return {left + 1, right + 1};
      }
      if (tmp_sum < target) {
        left++;
      } else {
        right--;
      }
    }
    return {};
  }
};
