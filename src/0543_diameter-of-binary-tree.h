#include "base.h"
typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  void MeasureDepthAndDiameter(TreeNode* root, int& depth, int& diameter) {
    if (!root) {
      depth = 0;
      diameter = 0;
      return;
    }

    int left_depth, left_diameter;
    MeasureDepthAndDiameter(root->left, left_depth, left_diameter);

    int right_depth, right_diameter;
    MeasureDepthAndDiameter(root->right, right_depth, right_diameter);

    depth = max(left_depth, right_depth) + 1;
    diameter = max(left_diameter, right_diameter);
    diameter = max(diameter, left_depth + right_depth);
  }

  int diameterOfBinaryTree(TreeNode* root) {
    int depth, diameter;
    MeasureDepthAndDiameter(root, depth, diameter);
    return diameter;
  }
};
