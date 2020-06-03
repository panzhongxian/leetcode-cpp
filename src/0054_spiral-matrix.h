#include "base.h"

class Solution {
 public:
  vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    vector<int> ret;
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return ret;
    }
    if (matrix[0].size() == 1) {
      for (auto& v : matrix) {
        ret.push_back(v[0]);
      }
      return ret;
    }
    int direction = 0;  // 0: right,  1: down, 2: left, 3: up
    // p1, p2
    // p4, p3
    auto p0 = pair<int, int>{0, 0};
    auto p1 = pair<int, int>{1, 0};
    auto p2 = pair<int, int>{0, matrix[0].size() - 1};
    auto p3 = pair<int, int>{matrix.size() - 1, matrix[0].size() - 1};
    auto p4 = pair<int, int>{matrix.size() - 1, 0};
#define PUSH_BACK                                                     \
  {                                                                   \
    /*cout << "(" << p0.first << ", " << p0.second << ")" << endl; */ \
    ret.push_back(matrix[p0.first][p0.second]);                       \
  }

    ret.push_back(matrix[0][0]);
    while (true) {
      switch (direction) {
        case 0:
          if (p0.second >= p2.second) {
            return ret;
          }
          while (p0.second < p2.second) {
            p0.second++;
            PUSH_BACK;
          }
          p2.first++;
          p2.second--;
          break;
        case 1:
          if (p0.first >= p3.first) {
            return ret;
          }
          while (p0.first < p3.first) {
            p0.first++;
            PUSH_BACK;
          }
          p3.first--;
          p3.second--;
          break;
        case 2:
          if (p0.second <= p4.second) {
            return ret;
          }
          while (p0.second > p4.second) {
            p0.second--;
            PUSH_BACK;
          }
          p4.first--;
          p4.second++;
          break;
        case 3:
          if (p0.first <= p1.first) {
            return ret;
          }
          while (p0.first > p1.first) {
            p0.first--;
            PUSH_BACK;
          }
          p1.first++;
          p1.second++;
          break;
      }
      direction = (direction + 1) % 4;
    }
    return ret;
  }
};
