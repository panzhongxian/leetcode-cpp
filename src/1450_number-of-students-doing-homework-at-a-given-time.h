#include "base.h"

class Solution {
 public:
  int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int ret = 0;
    for (int i = 0; i < startTime.size(); i++) {
      if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
        ret++;
      }
    }
    return ret;
  }
};
