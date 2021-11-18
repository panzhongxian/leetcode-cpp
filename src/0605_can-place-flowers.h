class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int last_flower_pos = -2;
    int can_insert_cnt = 0;
    for (int i = 0; i < flowerbed.size();) {
      if (flowerbed[i] == 1) {
        last_flower_pos = i;
        i++;
      } else if (last_flower_pos == i - 1) {  // 0
        i++;
      } else if (i == flowerbed.size() - 1) {
        can_insert_cnt++;
        i++;
      } else if (flowerbed[i + 1] == 0) {
        can_insert_cnt++;
        last_flower_pos = i;
        i += 2;
      } else {
        last_flower_pos = i + 1;
        i += 2;
      }
      if (can_insert_cnt >= n) {
        return true;
      }
    }
    return false;
  }
};
