class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    map<string, int> vec_pre_n;
    vec_pre_n[""] = 0;
    map<string, int> vec_n;
    for (size_t i = 1; i <= 2 * n; ++i) {
      for (map<string, int>::iterator iter = vec_pre_n.begin();
           iter != vec_pre_n.end(); iter++) {
        if (iter->second + 1 <= (n * 2 - i)) {  // TODO
          vec_n[iter->first + "("] = iter->second + 1;
        }
        if (iter->second - 1 >= 0) {
          vec_n[iter->first + ")"] = iter->second - 1;
        }
      }
      vec_pre_n = move(vec_n);
      vec_n.clear();
    }
    vector<string> ret(vec_pre_n.size());
    size_t i = 0;
    for (map<string, int>::iterator iter = vec_pre_n.begin();
         iter != vec_pre_n.end(); iter++, i++) {
      ret[i] = iter->first;
    }
    return ret;
  }
};
