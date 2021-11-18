class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string ret;
    do {
      columnNumber--;
      ret.insert(0, 1, columnNumber % 26 + 'A');
      columnNumber /= 26;
    } while (columnNumber);
    return ret;
  }
};
