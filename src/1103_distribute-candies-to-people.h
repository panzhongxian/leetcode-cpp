class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    auto n = num_people;
    vector<int> ret(num_people, 0);
    auto base = (n + 1) * n / 2;
    auto n_square = n * n;

    int k = 0;
    int sum = 0;
    while (true) {
      sum += base + k * n_square;
      if (sum > candies) {
        break;
      }
      k++;
    }

    sum = 0;
    if (k > 0) {
      for (int i = 0; i < num_people; i++) {
        if (i == 0) {
          ret[i] = (k * (k - 1) * n) >> 1;
          ret[i] += k;
        } else {
          ret[i] = ret[i - 1] + k;
        }
        sum += ret[i];
      }
    }

    base = k * n;
    for (int i = 0; i < num_people; i++) {
      auto to_give = base + i + 1;
      if (to_give + sum > candies) {
        ret[i] += candies - sum;
        return ret;
      }
      ret[i] += to_give;
      sum += to_give;
    }
    return ret;
  }
};
