// The timestamps for all TimeMap.set operations are strictly increasing.
class TimeMap {
 private:
  struct TimedValues {
    vector<int> tvec;
    vector<string> vvec;
  };
  map<string, TimedValues> key_time_value_map;

 public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    key_time_value_map[key].tvec.push_back(timestamp);
    key_time_value_map[key].vvec.push_back(value);
  }

  string get(string key, int timestamp) {
    if (key_time_value_map.find(key) == key_time_value_map.end()) {
      return "";
    }
    const auto& tvec = key_time_value_map[key].tvec;
    int left = 0;
    int right = tvec.size();
    int mid = (left + right) / 2;
    while (mid > left) {
      if (tvec[mid] > timestamp) {
        right = mid;
      } else {
        left = mid;
      }
      mid = (left + right) / 2;
    }

    if (mid == tvec.size()) {
      return tvec.back();
    } else if (tvec[mid] <= timestamp) {
      return key_time_value_map[key].vvec[mid];
    } else {
      return "";
    }
  }
};
