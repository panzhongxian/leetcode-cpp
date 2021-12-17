class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    map<int, int> m;
    for (int num : nums2) {
      while (!s.empty() && s.top() < num) {
        m[s.top()] = num;
        s.pop();
      }
      s.push(num);
    }
    vector<int> ret(nums1.size());
    int i = 0;
    for (int num : nums1) {
      ret[i++] = m.find(num) == m.end() ? -1 : m[num];
    }
    return ret;
  }
};
