class Solution {
 public:
  void splitDigits(int n, vector<char>& digits) {
    while (n) {
      digits.push_back(n % 10);
      n /= 10;
    }
  }

  int subtractProductAndSum(int n) {
    vector<char> digits;
    splitDigits(n, digits);

    int sum = 0;
    int product = 1;
    for (char c : digits) {
      sum += c;
      product *= c;
    }
    return product - sum;
  }
};
