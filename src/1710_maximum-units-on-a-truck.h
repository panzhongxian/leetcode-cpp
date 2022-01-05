#include "base.h"

class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [](const vector<int>& v1, const vector<int>& v2) {
           return v1[1] > v2[1];
         });

    int ret = 0;
    for (int i = 0; i < boxTypes.size(); i++) {
      if (truckSize >= boxTypes[i][0]) {
        ret += boxTypes[i][0] * boxTypes[i][1];
        truckSize -= boxTypes[i][0];
      } else {
        ret += truckSize * boxTypes[i][1];

        return ret;
      }
    }
    return ret;
  }
};
