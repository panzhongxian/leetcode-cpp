class Solution {
 public:
  int get_root_of_square_number(int i) {
    int root = floor(sqrt(i));
    if (root * root == i) {
      return root;
    }
    return 0;
  }
  bool is_prime(int n) {
    for (int i = 2; i <= floor(sqrt(n)); i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
  bool isThree(int n) {
    // check whether n is a squre number and the root is prime number
    if (n < 2) {
      return false;
    }
    auto root = get_root_of_square_number(n);
    return root > 0 && is_prime(root);
  }
};
