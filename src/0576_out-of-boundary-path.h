#include <algorithm>
#include <iostream>
#include <vector>

constexpr size_t modulo = 1000000007;
using namespace std;
class Solution {
 public:
  void OneMoreStep(const vector<vector<int>>& m1, vector<vector<int>>& m2) {
    for (int i = 0; i < m1.size(); i++) {
      for (int j = 0; j < m1[0].size(); j++) {
        size_t curr_val = 0;
        if (i > 0) {
          curr_val += m1[i - 1][j];
          curr_val %= modulo;
        }
        if (j > 0) {
          curr_val += m1[i][j - 1];
          curr_val %= modulo;
        }
        if (i + 1 < m1.size()) {
          curr_val += m1[i + 1][j];
          curr_val %= modulo;
        }
        if (j + 1 < m1[0].size()) {
          curr_val += m1[i][j + 1];
          curr_val %= modulo;
        }
        m2[i][j] = curr_val;
      }
    }
  }
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<int>> matrix1(m, vector<int>(n));
    vector<vector<int>> matrix2(m, vector<int>(n));

    if (maxMove == 0) {
      return 0;
    }

    for (auto& v : matrix1) {
      v.front()++;
      v.back()++;
    }
    for (int i = 0; i < matrix1[0].size(); i++) {
      matrix1.front()[i]++;
      matrix1.back()[i]++;
    }

    size_t ret = matrix1[startRow][startColumn];
    for (int i = 1; i < maxMove; i++) {
      OneMoreStep(matrix1, matrix2);
      matrix2.swap(matrix1);
      ret += matrix1[startRow][startColumn];
      ret %= modulo;
    }
    return ret;
  }
};
