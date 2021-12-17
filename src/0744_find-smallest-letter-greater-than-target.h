class Solution {
 public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int left = 0;
    int right = letters.size();
    int mid;
    while (left < right) {
      mid = (left + right) / 2;
      if (letters[mid] <= target) {
        left = mid + 1;
      } else if (letters[mid] == target + 1) {
        return target + 1;
      } else {
        right = mid;
      }
    }
    return left < letters.size() ? letters[left] : letters[0];
  }
};
