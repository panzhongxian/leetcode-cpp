#include "0114_flatten-binary-tree-to-linked-list.h"

TEST(S, Demo) {
  Solution s;
  s.flatten(base::TreeNodeFactory<int>("[]"));
  s.flatten(base::TreeNodeFactory<int>("[1]"));
  s.flatten(base::TreeNodeFactory<int>("[1,2,2,3,3,null,null,4,5]"));
  s.flatten(base::TreeNodeFactory<int>("[1,2,2,3,3,null,null,4,5]"));
  s.flatten(base::TreeNodeFactory<int>("[1,2,2,3,3,null,null,4,5]"));
}
