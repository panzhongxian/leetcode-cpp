#include "0146_lru-cache.h"

TEST(S, Demo) {
  LRUCache cache(2);

  cache.put(1, 1);
  cache.put(2, 2);
  EXPECT_EQ(cache.get(1), 1);   // returns 1
  cache.put(3, 3);              // evicts key 2
  EXPECT_EQ(cache.get(2), -1);  // returns -1 (not found)
  cache.put(4, 4);              // evicts key 1
  EXPECT_EQ(cache.get(1), -1);  // returns -1 (not found)
  EXPECT_EQ(cache.get(3), 3);   // returns 3
  EXPECT_EQ(cache.get(4), 4);   // returns 4
}
