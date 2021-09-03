#include "0341_flatten-nested-list-iterator.h"

#include "base.h"
#include "nested_integer.h"

TEST(S, Demo) {
  NestedInteger nested_integer{1, {2, 3}, {4, {5}}};
  NestedIterator i(nested_integer.getList());
  vector<int> result;
  vector<int> expected_result{1, 2, 3, 4, 5};
  while (i.hasNext()) result.push_back(i.next());
  EXPECT_EQ(result, expected_result);
}
