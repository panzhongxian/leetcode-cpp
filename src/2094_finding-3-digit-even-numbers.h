class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    int m[10] = {0};
    vector<int> ret;

    for (int digit : digits) {
      m[digit]++;
    }

    for (int i = 1; i < 10; i++) {
      if (m[i] > 0) {
        m[i]--;
        for (int j = 0; j < 10; j++) {
          if (m[j] == 0) {
            continue;
          }
          m[j]--;
          for (int k = 0; k < 10; k += 2) {
            if (m[k] == 0) {
              continue;
            }
            ret.push_back(i * 100 + j * 10 + k);
          }
          m[j]++;
        }
        m[i]++;
      }
    }
    return ret;
  }
};
