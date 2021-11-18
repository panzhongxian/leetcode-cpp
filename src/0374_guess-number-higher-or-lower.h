class Solution {
 public:
  int guessNumber(int n) {
    if (n == 1) {
      return 1;
    }
    int step = n / 2;
    int pick_to_check = n / 2;

    while (true) {
      int pick_ret = guess(pick_to_check);
      if (pick_ret == 0) {
        return pick_to_check;
      } else if (pick_ret < 0) {
        step = step == 1 ? 1 : (step / 2);
        pick_to_check -= step;
      } else {
        step = step == 1 ? 1 : (step / 2);
        pick_to_check += step;
      }
    }
  }
};
