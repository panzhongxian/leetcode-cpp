#include "base.h"

class Solution {
 public:
  int dayOfYear(string date) {
    int year = atoi(date.c_str());
    auto pos = date.find('-');
    int month = atoi(date.substr(pos + 1).c_str());
    pos = date.find('-', pos + 1);
    int day = atoi(date.substr(pos + 1).c_str());

    int base[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
      base[2] = 29;
    }

    int ret = day;
    for (int i = 0; i < month; i++) {
      ret += base[i];
    }
    return ret;
  }
};
