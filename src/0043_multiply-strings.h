#include <algorithm>
#include <string>

using std::string;
class Solution {
 public:
  inline void fit_value_carry(int& value, int& carry) {
    carry = value / 10;
    value %= 10;
  }

  string add(const string& num1, const string& num2) {
    string ret;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int value;
    while (i >= 0 && j >= 0) {
      value = num1[i--] + num2[j--] + carry;
      fit_value_carry(value, carry);
      ret.push_back(value);
    }

    while (i >= 0) {
      value = num1[i--] + carry;
      fit_value_carry(value, carry);
      ret.push_back(value);
    }
    while (j >= 0) {
      value = num2[j--] + carry;
      fit_value_carry(value, carry);
      ret.push_back(value);
    }

    if (carry > 0) {
      ret.push_back(1);
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  string to_string(string num) {
    std::for_each(num.begin(), num.end(), [](char& c) { c += '0'; });
    return num;
  }

  string multiply_digit(const string& num1, int digit) {
    if (digit == 0) {
      return 0;
    }

    string ret;

    int carry = 0;
    int value;
    for (int i = num1.size() - 1; i >= 0; i--) {
      value = carry + digit * num1[i];
      fit_value_carry(value, carry);
      ret.push_back(value);
    }
    if (carry > 0) {
      ret.push_back(carry);
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";  // <<==
    }

    std::for_each(num1.begin(), num1.end(), [](char& c) { c -= '0'; });
    std::for_each(num2.begin(), num2.end(), [](char& c) { c -= '0'; });

    string ret{0};
    string shift = "";
    reverse(num2.begin(), num2.end());
    for (char c : num2) {
      if (c != 0) {
        ret = add(ret, multiply_digit(num1, c) + shift);
      }
      shift.push_back(0);
    }
    std::for_each(ret.begin(), ret.end(), [](char& c) { c += '0'; });
    return ret;
  }
};
