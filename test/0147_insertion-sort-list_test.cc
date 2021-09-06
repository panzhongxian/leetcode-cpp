#include "0147_insertion-sort-list.h"

#include <algorithm>
#include <random>

TEST(S, Demo) {
  auto rng = std::default_random_engine{};
  vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> v2(v1);

  for (int i = 0; i < 1000; i++) {
    Solution s;
    std::shuffle(v2.begin(), v2.end(), rng);
    auto head = ListNode::Factory(v2);
    head = s.insertionSortList(head);
    EXPECT_EQ(ListNode::Dump(head), v1);
  }
}
