class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start,
                              int destination) {
    if (start > destination) {
      swap(start, destination);
    }
    int sum = 0;
    for (int i = 0; i < distance.size(); i++) {
      sum += distance[i];
    }
    int dist = 0;
    for (int i = start; i < destination; i++) {
      dist += distance[i];
    }
    return min(dist, sum - dist);
  }
};
