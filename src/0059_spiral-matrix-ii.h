class Solution {
 public:
  // direction = 0 : left -> right
  //             1 : up -> down
  //             2 : right -> left
  //             3 : down -> up
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret = vector(n, vector<int>(n, 0));

    int direction = 0;
    int x = 0;
    int y = 0;

    int end = n * n;
    for (int i = 1; i <= end; i++) {
      ret[x][y] = i;
      switch (direction) {
        case 0:
          if (y + 1 >= n || ret[x][y + 1] > 0) {
            direction++;
            x++;
          } else {
            y++;
          }
          break;
        case 1:
          if (x + 1 >= n || ret[x + 1][y] > 0) {
            direction++;
            y--;
          } else {
            x++;
          }
          break;
        case 2:
          if (y == 0 || ret[x][y - 1] > 0) {
            direction++;
            x--;
          } else {
            y--;
          }
          break;
        case 3:
          if (x == 0 || ret[x - 1][y] > 0) {
            direction = 0;
            y++;
          } else {
            x--;
          }
          break;
      }
    }
    return ret;
  }
};
