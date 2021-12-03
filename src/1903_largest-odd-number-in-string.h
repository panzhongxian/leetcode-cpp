class Solution {
public:
  string largestOddNumber(string num) {
    auto pos = num.find_last_of("13579");
    if (pos == string::npos)
      return "";

    auto start = num.find_first_not_of("0");
    return num.substr(start, pos - start + 1);
  }
};
