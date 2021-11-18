#include "base.h"
class SolutionBak {
 public:
  int countPrimes(int n) {
    if (n <= 1) {
      return 0;
    }

    bool is_prime[n + 1];
    int max_prime_factor[n + 1];

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i < n; i++) {
      is_prime[i] = true;
      max_prime_factor[i] = -1;
    }

    for (int i = 2; i <= n / i; i++) {
      if (!is_prime[i]) {
        continue;
      }

      int end = n / i;
      int index = i * i;
      int j = i;
      while (j <= end) {
        if (is_prime[j] || max_prime_factor[j] == i) {
          is_prime[index] = false;
          max_prime_factor[index] = i;
        }
        index += i;
        j++;
      }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
      if (is_prime[i]) {
        ret++;
      }
    }
    return ret;
  }
};

class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 1) {
      return 0;
    }

    int is_prime[n + 1];
    memset(is_prime, 1, sizeof(int) * (n + 1));
    is_prime[0] = 0;
    is_prime[1] = 0;

    for (int i = 2; i <= n / i; i++) {
      if (is_prime[i]) {
        for (int index = i * i; index < n; index += i) {
          // cout << "!" << index << endl;
          is_prime[index] = 0;
        }
      }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
      if (is_prime[i]) {
        ret++;
      }
    }
    return ret;
  }
};
