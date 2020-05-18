#include "base.h"
class Solution {
public:
};

#if defined(LC_TEST)
TEST(S, Demo) {
  Solution s;
  // execute s.Solve
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

#elif defined(LC_BM)

static void BM_S(benchmark::State &state) {
  for (auto _ : state) {
    Solution s;
    // execute s.Solve
  }
}

BENCHMARK(BM_S);

BENCHMARK_MAIN();

#endif
