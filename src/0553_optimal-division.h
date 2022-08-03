#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
 public:
  tuple<double, string, double, string> MinMaxDivision(
      const vector<int>& nums, const vector<vector<double>>& max_division,
      const vector<vector<double>>& min_division,
      const vector<vector<string>>& max_div_expr,
      const vector<vector<string>>& min_div_expr, int i, int j) {
    if (i == j) {
      return {nums[i], to_string(nums[i]), nums[i], to_string(nums[i])};
    }
    double max_val = 0.0;
    double min_val = nums[i];
    string max_expr;
    string min_expr = to_string(nums[i]);

    for (int k = i; k < j; k++) {
      double t = max_division[i][k] / min_division[k + 1][j];
      if (t > max_val) {
        max_val = t;
        max_expr = max_div_expr[i][k] + "/";
        max_expr += min_div_expr[k + 1][j].find('/') == string::npos
                        ? min_div_expr[k + 1][j]
                        : "(" + min_div_expr[k + 1][j] + ")";
      }

      t = min_division[i][k] / max_division[k + 1][j];
      if (t < min_val) {
        min_val = t;
        min_expr = min_div_expr[i][k] + "/";
        min_expr += max_div_expr[k + 1][j].find('/') == string::npos
                        ? max_div_expr[k + 1][j]
                        : "(" + max_div_expr[k + 1][j] + ")";
      }
    }
    return {max_val, max_expr, min_val, min_expr};
  };

  string optimalDivision(const vector<int>& nums) {
    int v_len = nums.size();
    vector<vector<double>> max_division(v_len, vector<double>(v_len));
    auto min_division = max_division;
    vector<vector<string>> max_div_expr(v_len, vector<string>(v_len));
    auto min_div_expr = max_div_expr;
    for (int i = 0; i < v_len; i++) {
      for (int j = 0; j < v_len - i; j++) {
        int k = i + j;
        auto [max_val, max_expr, min_val, min_expr] = MinMaxDivision(
            nums, max_division, min_division, max_div_expr, min_div_expr, j, k);

        max_division[j][k] = max_val;
        max_div_expr[j][k] = move(max_expr);
        min_division[j][k] = min_val;
        min_div_expr[j][k] = move(min_expr);
      }
    }

    return max_div_expr[0].back();
  }
};
