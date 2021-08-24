#include <cstdio>
#include <vector>

using std::vector;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int k = matrix.size() - 1;
    int i_upper = matrix.size() / 2;
    int j_upper = (matrix.size() + 1) / 2;

    for (int i = 0; i < i_upper; i++) {
      for (int j = 0; j < j_upper; j++) {
        int a = matrix[i][j];
        matrix[i][j] = matrix[k - j][i];
        matrix[k - j][i] = matrix[k - i][k - j];
        matrix[k - i][k - j] = matrix[j][k - i];
        matrix[j][k - i] = a;
#ifdef LEETCODE_DEBUG
        printf("(%d, %d),(%d, %d),(%d, %d),(%d, %d)\n",  //
               i, j,                                     //
               j, k - i,                                 //
               k - i, k - j,                             //
               k - j, i                                  //
        );
#endif
      }
    }
#ifdef LEETCODE_DEBUG
    printf("\n");
#endif
  }
};
