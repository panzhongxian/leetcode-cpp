class Solution {
 public:
  int calPoints(vector<string> &ops) {
    int ret = 0;
    vector<int> record;
    for (auto &s : ops) {
      if (s == "C") {
        record.erase(record.begin() + record.size() - 1);
      } else if (s == "D") {
        record.push_back(record.back() * 2);
      } else if (s == "+") {
        record.push_back(record.back() + record[record.size() - 2]);
      } else {
        record.push_back(atoi(s.c_str()));
      }
    }

    for (int i : record) {
      ret += i;
    }

    return ret;
  }
};
