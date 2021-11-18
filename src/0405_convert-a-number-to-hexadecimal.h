class Solution {
 public:
  string toHex(int num) {
    string ret;
    const int mask = 0x0000000f;
    for (int i = 0; i < 8; i++) {
      int digit = num & mask;
      if (digit < 10) {
        ret.insert(ret.begin(), '0' + digit);
      } else {
        ret.insert(ret.begin(), 'a' + digit - 10);
      }
      num >>= 4;
    }

    // lstrip('0')
    if (ret.find_first_not_of("0") == string::npos) {
      return "0";
    } else {
      return ret.substr(ret.find_first_not_of("0"));
    }
  }
};
