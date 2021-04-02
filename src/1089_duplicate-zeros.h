class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    if (arr.size() < 2) {
      return;
    }

    int p1, p2;
    p1 = 0;
    p2 = 0;
    while (p2 < arr.size()) {
      if (arr[p1++] == 0) {
        p2 += 2;
      } else {
        p2 += 1;
      }
    }
    p1--;
    p2--;
    cout << p1 << ", " << p2 << endl;
    if (p2 >= arr.size()) {
      p2--;
      arr[p2--] = arr[p1--];
    }
    while (p2 > p1) {
      int cur = arr[p1--];
      if (cur == 0) {
        arr[p2--] = 0;
        arr[p2--] = 0;
      } else {
        arr[p2--] = cur;
      }
    }
  }
};
