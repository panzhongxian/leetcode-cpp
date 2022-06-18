class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    sort(deadends.begin(), deadends.end());
    vector<string> cur_codes{"0000"};
    vector<string> new_codes;
    char searched[10000] = {0};
    int ret = 0;
    string code, new_code;

    while (true) {
      for (auto& code : cur_codes) {
        int code_val = atoi(code.c_str());
        if (searched[code_val]) {
          continue;
        }
        searched[code_val] = 1;
        if (binary_search(deadends.begin(), deadends.end(), code)) {
          continue;
        }
        if (code == target) {
          return ret;
        }
        for (int i = 0; i < target.size(); i++) {
          new_code = code;
          new_code[i] = new_code[i] == '9' ? '0' : new_code[i] + 1;
          new_codes.push_back(new_code);
        }
        for (int i = 0; i < target.size(); i++) {
          new_code = code;
          new_code[i] = new_code[i] == '0' ? '9' : new_code[i] - 1;
          new_codes.push_back(new_code);
        }
      }

      ret++;
      cur_codes = move(new_codes);
      if (cur_codes.empty()) {
        return -1;
      }
    }
    return -1;
  }
};
