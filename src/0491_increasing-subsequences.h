#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct Node {
  int val{INT_MIN};
  map<int, Node*> children;

 public:
  Node() = default;
  explicit Node(int num) : val(num) {}
  void InsertChild(int num) {
    for (auto& [k, v] : children) {
      v->InsertChild(num);
    }
    if (children.find(num) == children.end() && val <= num) {
      children[num] = new Node(num);
    }
  }
  vector<vector<int>> DumpChildren(vector<int> prefix) {
    prefix.push_back(val);
    vector<vector<int>> ret{prefix};
    if (children.empty()) {
      return ret;
    }
    for (auto& [k, v] : children) {
      auto sub_ret = v->DumpChildren(prefix);
      ret.insert(ret.end(), sub_ret.begin(), sub_ret.end());
    }
    return ret;
  }
  vector<vector<int>> DumpResult() {
    vector<int> prefix;
    vector<vector<int>> ret;
    for (auto& [k, v] : children) {
      auto sub_ret = v->DumpChildren(prefix);
      copy_if(sub_ret.begin(), sub_ret.end(), std::back_inserter(ret),
              [](vector<int>& v) { return v.size() > 1; });
    }
    return ret;
  }
};

class Solution {
 public:
  vector<vector<int>> findSubsequences(const vector<int>& nums) {
    auto root = new Node();
    for (int num : nums) {
      root->InsertChild(num);
    }
    auto ret = root->DumpResult();
    return ret;
  }
};
