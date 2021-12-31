class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size();
    int mid;

    while (true) {
      mid = (left + right) / 2;
      if (arr[mid] > arr[mid - 1]) {
        if (arr[mid] > arr[mid + 1]) {
          return mid;
        }
        left = mid + 1;
      } else {
        right = mid;
      }
      if (left >= right - 1) {
        return left;
      }
    }
    return -1;
  }
};
