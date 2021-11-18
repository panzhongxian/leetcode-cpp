#include "0443_string-compression.h"

#include <algorithm>

#include "base.h"

TEST(S, Demo) {
  vector<char> char_array{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  Solution s;
  int len = s.compress(char_array);
  vector<char> expect_result{'a', '2', 'b', '2', 'c', '2'};
  EXPECT_EQ(std::equal(char_array.begin(), char_array.begin() + len,
                       expect_result.begin()),
            0);
}
