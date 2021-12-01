#include "base.h"
class Solution {
  enum Direction { left = 1, right = 2, up = 4, down = 8 };
  class Node {
  public:
    int i;
    int j;
    int directions; // 0b1111: left,right,up,down
    int from_direction;

    Node(int a, int b, int c = 0b1111, int d = 0)
        : i(a), j(b), directions(c), from_direction(d) {}

    vector<Node> get_next_nodes() {
      vector<Node> ret;
      switch (from_direction) {
      case down:
        directions &= (left | right | down);
        break;
      case left:
        directions &= (left | up);
        break;
      case right:
        directions &= (right | up);
        break;
      case up:
        directions &= up;
        break;
      }

      if (directions & left) {
        ret.push_back(Node(i - 1, j, directions & (~right), left));
      }
      if (directions & right) {
        ret.push_back(Node(i + 1, j, directions & (~left), right));
      }
      if (directions & up) {
        ret.push_back(Node(i, j - 1, directions & (~down), up));
      }
      if (directions & down) {
        ret.push_back(Node(i, j + 1, directions & (~up), down));
      }
      return ret;
    }
  };

public:
  vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                        int cCenter) {
    vector<vector<int>> ret;
    queue<Node> q;
    q.push(Node(rCenter, cCenter));
    while (!q.empty()) {
      auto &node = q.front();
      vector<Node> v = node.get_next_nodes();
      for (auto &n : v) {
        if (n.i >= 0 && n.i < rows && n.j >= 0 && n.j < cols) {
          q.push(n);
        }
      }
      ret.push_back(vector<int>{node.i, node.j});
      // cout << "next_node: (" << node.i << ", " << node.j << ")" << endl;
      q.pop();
    }
    return ret;
  }
};
