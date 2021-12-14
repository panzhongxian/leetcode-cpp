class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int curr_altitude = 0;
    int ret = 0;
    for (int n : gain) {
      curr_altitude += n;
      if (curr_altitude > ret) {
        ret = curr_altitude;
      }
    }
    return ret;
  }
};
