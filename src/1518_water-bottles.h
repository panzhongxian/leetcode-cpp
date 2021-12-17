class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int ret = numBottles;
    while (numBottles >= numExchange) {
      int i = numBottles / numExchange;
      numBottles = i + (numBottles % numExchange);
      ret += i;
    }
    return ret;
  }
};
