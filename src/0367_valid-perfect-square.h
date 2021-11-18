class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num == 0 || num == 1) {
      return true;
    }

    int left = 0;
    int right = num;
    int mid;

    while (left < right) {
      mid = (left + right) / 2;
      int t = num / mid;
      if (t > mid) {
        left = mid + 1;
      } else if (t < mid) {
        right = mid;
      } else {
        return num % mid == 0;
      }
    }
    return false;
  }
};
