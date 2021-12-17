struct PointWithOrigin {
  int i;
  int j;
};

class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    if (image[sr][sc] == newColor) {
      return image;
    }
    int old_color = image[sr][sc];
    queue<PointWithOrigin> q;
    q.push(PointWithOrigin{sr, sc});

    while (!q.empty()) {
      auto& p = q.front();
      if (p.i > 0 && image[p.i - 1][p.j] == old_color) {
        q.push(PointWithOrigin{p.i - 1, p.j});
      }
      if (p.i + 1 < image.size() && image[p.i + 1][p.j] == old_color) {
        q.push(PointWithOrigin{p.i + 1, p.j});
      }
      if (p.j > 0 && image[p.i][p.j - 1] == old_color) {
        q.push(PointWithOrigin{p.i, p.j - 1});
      }
      if (p.j + 1 < image[0].size() && image[p.i][p.j + 1] == old_color) {
        q.push(PointWithOrigin{p.i, p.j + 1});
      }
      image[p.i][p.j] = newColor;
      q.pop();
    }
    return image;
  }
};
