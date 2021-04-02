class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    if (A.size() <= 1) {
      return A;
    }
    vector<int> ret(A.size());
    int p1 = 0;
    int p2 = A.size() - 1;
    for (int a : A) {
      if (a & 1) {
        ret[p2--] = a;
      } else {
        ret[p1++] = a;
      }
    }
    return ret;
  }
};
