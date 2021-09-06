#include <iostream>
#include <vector>

using std::vector;

// (TODO)改进：切成4份进行查找，每份左上右下两个顶点确认是否在其中

#define check_exit()                    \
  if (left == right || top == bottom) { \
    return false;                       \
  }

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // 左、下、右、上不断的循环限制
    int left = 0;
    int right = matrix[0].size();
    int top = 0;
    int bottom = matrix.size();
    bool all_pass_flag;

    while (true) {
      // left line: find all elem less than target.
      all_pass_flag = true;
      for (int i = top; i < bottom; i++) {
        if (matrix[i][left] == target) {
          return true;
        }
        if (matrix[i][left] > target) {
          bottom = i;
          all_pass_flag = false;
          break;
        }
      }

      if (all_pass_flag) {
        left++;
      }
      check_exit();

      // top line: find all elem less than target.
      all_pass_flag = true;
      for (int i = left; i < right; i++) {
        if (matrix[top][i] == target) {
          return true;
        }
        if (matrix[top][i] > target) {
          right = i;
          all_pass_flag = false;
          break;
        }
      }
      if (all_pass_flag) {
        top++;
      }
      check_exit();

      all_pass_flag = true;
      // right line: find all elem larger than target.
      for (int i = top; i < bottom; i++) {
        if (matrix[i][right - 1] == target) {
          return true;
        }

        if (matrix[i][right - 1] > target) {
          all_pass_flag = false;
          top = i;
          break;
        }
      }

      if (all_pass_flag) {
        right--;
      }
      check_exit();

      // bottom line: find all elem larger than targe.
      all_pass_flag = true;
      for (int i = left; i < right; i++) {
        if (matrix[bottom - 1][i] == target) {
          return true;
        }
        if (matrix[bottom - 1][i] > target) {
          all_pass_flag = false;
          left = i;
          break;
        }
      }
      if (all_pass_flag) {
        bottom--;
      }
      check_exit();
    }

    return false;
  }
};
