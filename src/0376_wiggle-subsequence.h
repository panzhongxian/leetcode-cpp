#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int last_up_num = INT_MAX;
    int last_down_num = INT_MIN;
    int up_serial_len = 0;
    int down_serial_len = 0;
    for (int num : nums) {
      int new_last_up_num = last_up_num;
      int new_last_down_num = last_down_num;
      int new_up_serial_len = up_serial_len;
      int new_down_serial_len = down_serial_len;
      if (num < last_up_num) {
        if (up_serial_len + 1 > down_serial_len) {
          new_last_down_num = num;
          new_down_serial_len = up_serial_len + 1;
        }
      } else {
        new_last_up_num = num;
      }
      if (num > last_down_num) {
        if (down_serial_len + 1 > up_serial_len) {
          new_last_up_num = num;
          new_up_serial_len = down_serial_len + 1;
        }
      } else {
        new_last_down_num = num;
      }
      last_up_num = new_last_up_num;
      last_down_num = new_last_down_num;
      up_serial_len = new_up_serial_len;
      down_serial_len = new_down_serial_len;
    }

    return max(up_serial_len, down_serial_len);
  }
};
