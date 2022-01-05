#include "base.h"

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if (accumulate(gas.begin(), gas.end(), 0) <
        accumulate(cost.begin(), cost.end(), 0)) {
      return -1;
    }
    int gas_tank = 0;
    int start_station = 0;
    for (int i = 0; i < gas.size(); i++) {
      gas_tank += gas[i] - cost[i];
      if (gas_tank < 0) {
        start_station = i + 1;
        gas_tank = 0;
      }
    }
    return start_station;
  }
};
