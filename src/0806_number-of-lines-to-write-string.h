class Solution {
 public:
  vector<int> numberOfLines(vector<int>& widths, string s) {
    int cur_line_width = 0;
    int lines = 1;
    int res = 0;

    for (char c : s) {
      int width = widths[c - 'a'];
      if (cur_line_width + width > 100) {
        lines++;
        cur_line_width = width;
        res = width;
      } else {
        cur_line_width += width;
        res += width;
      }
    }
    return vector<int>{lines, res};
  }
};
