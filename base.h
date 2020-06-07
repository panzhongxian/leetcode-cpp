#ifndef _BASE_H_
#define _BASE_H_

#include <algorithm>
#include <cmath>
#include <map>
#include <ostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "absl/strings/str_split.h"
#include "absl/strings/string_view.h"
#include "benchmark/benchmark.h"
#include "gtest/gtest.h"

using namespace std;

namespace base {

template <class T>
struct ListNode {
  T val;
  ListNode *next;
  ListNode(T x) : val(x), next(NULL) {}
  static ListNode *Factory(const std::initializer_list<T> l) {
    if (l.size() == 0) return nullptr;
    auto iter = l.begin();
    ListNode *cur = new ListNode(*iter);
    ListNode *ret = cur;
    ++iter;
    while (iter != l.end()) {
      cur->next = new ListNode(*iter);
      cur = cur->next;
      ++iter;
    }
    return ret;
  }
  static vector<T> Dump(ListNode *head) {
    vector<T> ret;
    while (head) {
      ret.push_back(head->val);
      head = head->next;
    }

    return ret;
  }
};

template <class T>
struct BiDirListNode {
  T val;
  BiDirListNode *prev;
  BiDirListNode *next;
  BiDirListNode() : prev(NULL), next(NULL) {}
  BiDirListNode(T x) : val(x), prev(NULL), next(NULL) {}
};

template <class T>
class TreeNode {
 public:
  T val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;
  TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  TreeNode(T x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
  TreeNode(T x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

template <class T>
TreeNode<T> *TreeNodeFactory(const std::string &input) {
  absl::string_view list_str(input);
  vector<TreeNode<T> *> level_traversal;

  absl::ConsumePrefix(&list_str, "[");
  absl::ConsumeSuffix(&list_str, "]");
  if (list_str == "") {
    return nullptr;
  }

  for (auto c : absl::StrSplit(list_str, ',')) {
    while (absl::ConsumePrefix(&c, " ")) {
    }
    while (absl::ConsumeSuffix(&c, " ")) {
    }
    if (absl::AsciiStrToLower(c) == "null") {
      level_traversal.push_back(nullptr);
      continue;
    }

    T val;
    stringstream(string(c)) >> val;
    level_traversal.push_back(new TreeNode<T>(val));
  }

  size_t cur_root_idx = 0;
  int node_pos = 0;  // 0: left,  1: right
  TreeNode<T> *cur_root;
  for (size_t i = 1; i < level_traversal.size(); ++i) {
    cur_root = level_traversal[cur_root_idx];

    if (node_pos == 0) {
      cur_root->left = level_traversal[i];
    } else {
      cur_root->right = level_traversal[i];
      do {
        ++cur_root_idx;
        if (cur_root_idx > i) {
          return level_traversal[0];
        }
      } while (!level_traversal[cur_root_idx]);
    }
    node_pos = !node_pos;
  }

  return level_traversal[0];
}

template <class T>
vector<T> DumpTree(TreeNode<T> *t) {
  if (!t) return vector<T>();

  // vector<T*>
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]";
  return os;
}

template <class T>
void DumpVector(vector<T> v) {
  cout << v;
}

// TODO 应该怎么派生TreeNode的类，才能使用上边的工厂函数？
template ostream &operator<<<int>(ostream &os, const vector<int> &v);
template ostream &operator<<<vector<int>>(ostream &os,
                                          const vector<vector<int>> &v);

}  // namespace base

using base::operator<<;

// 输出pair坐标点
#define COUT_POINT(x) \
  cout << #x << ": (" << x.first << ", " << x.second << ")" << endl;

#define COUT_VALUE(x) cout << #x << ": " << x << endl;
#define COUT_PAIR(x, y) cout << "[" << x << "," << y << "]" << endl;

#endif
