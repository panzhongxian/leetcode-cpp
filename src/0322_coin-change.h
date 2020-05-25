#include "base.h"

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) {
      return 0;
    }

    if (coins.size() == 0) {
      return -1;
    }

    // 该分支可以省略，加上可以提高效率
    if (coins.size() == 1) {
      return (amount % coins[0] == 0) ? (amount / coins[0]) : -1;
    }

    vector<int> little_coins;
    int max_coin = 0;
    for (int j : coins) {
      if (amount == j) {
        return 1;
      }
      if (amount < j) {
        continue;
      }
      if (max_coin < j) {
        max_coin = j;
      }
      little_coins.push_back(j);
    }

    vector<int> min_coin_vec(amount + 1, -1);
    min_coin_vec[0] = 0;

    for (auto j : little_coins) {
      min_coin_vec[j] = 1;
    }

    for (size_t i = 0; i <= (size_t)amount; ++i) {
      if (min_coin_vec[i] == 1) {
        continue;
      }
      int pre_min_coin = -1;
      for (size_t coin : little_coins) {
        if (i < coin || min_coin_vec[i - coin] == -1) {  // i - coin < 0
          continue;
        }

        if (pre_min_coin == -1) {
          pre_min_coin = min_coin_vec[i - coin];
        } else {
          pre_min_coin = min(pre_min_coin, min_coin_vec[i - coin]);
        }
      }

      if (pre_min_coin != -1) {
        min_coin_vec[i] = pre_min_coin + 1;
      }
    }
    return min_coin_vec.back();
  }
};
