#include "1030_matrix-cells-in-distance-order.h"

bool validate_cells_dist_order(int rows, int cols, int rCenter, int cCenter) {
  Solution s;
  auto vv = s.allCellsDistOrder(rows, cols, rCenter, cCenter);
  if (vv.size() != rows * cols) {
    return false;
  };
  int last_distance = 0;
  for (auto &v : vv) {
    int curr_distance = abs(v[0] - rCenter) + abs(v[1] - cCenter);
    if (curr_distance < last_distance) {
      return false;
    }
    last_distance = curr_distance;
  }
  return true;
}

TEST(Solution, Demo) {
  EXPECT_TRUE(validate_cells_dist_order(2, 2, 0, 1));
  EXPECT_TRUE(validate_cells_dist_order(2, 3, 1, 2));
  EXPECT_TRUE(validate_cells_dist_order(10, 10, 3, 7));
  EXPECT_TRUE(validate_cells_dist_order(100, 100, 38, 78));
}
