class Solution {
 public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (auto student : students) {
      q.push(student);
    }
    int i = 0;
    while (true) {
      int counter = q.size();
      bool match_flag = false;
      while (counter > 0) {
        if (q.front() == sandwiches[i]) {
          i++;
          q.pop();
          match_flag = true;
          break;
        } else {
          q.push(q.front());
          q.pop();
          counter--;
        }
      }
      if (!match_flag) {
        return q.size();
      }
    }
    return 0;
  }
};
