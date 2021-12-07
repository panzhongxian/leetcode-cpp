class Solution {
public:
  bool checkIfPangram(string sentence) {
    int32_t m = 0;
    for (char c : sentence) {
      m |= (1 << (c - 'a'));
      if (m == 0x3ffffff) {
        return true;
      }
    }

    return false;
  }
};
