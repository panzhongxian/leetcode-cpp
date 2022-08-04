#include <stack>
#include <vector>
using namespace std;
enum BreakType {
  kBreakTypeUnknown,
  kBreakTypeOutOfRange,
  kBreakTypeCircle,
  kBreakTypeSinked
};

class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int ret = 0;
    stack<int> s;
    vector<int> max_len(nums.size());
    int index, new_index;

    for (int i = 0; i < nums.size(); i++) {
      index = i;
      if (max_len[index] != 0) {
        continue;
      }

      int break_type{kBreakTypeUnknown};
      int base_size = 0;
      while (true) {
        if (index >= nums.size()) {
          break_type = kBreakTypeOutOfRange;
          break;
        }
        if (max_len[index] > 0) {
          break_type = kBreakTypeSinked;
          base_size = max_len[index];
          break;
        }
        if (nums[index] < 0) {
          break_type = kBreakTypeCircle;
          base_size = s.size();
          break;
        }
        new_index = nums[index];
        nums[index] = -nums[index] - 1;
        s.push(index);
        index = new_index;
      }
      while (!s.empty()) {
        index = s.top();
        switch (break_type) {
          case kBreakTypeOutOfRange:
          case kBreakTypeSinked:
            base_size++;
            max_len[index] = base_size;
            break;
          case kBreakTypeCircle:
            max_len[index] = base_size;
            break;
          default:  //
              ;     // pass
        }
        s.pop();
        ret = max(max_len[index], ret);
        nums[index] = -nums[index] - 1;
      }
    }
    return ret;
  }
};
