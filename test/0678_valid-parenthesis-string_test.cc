#include "0678_valid-parenthesis-string.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.checkValidString("(((()))"), false);
  EXPECT_EQ(s.checkValidString("(((*)))"), true);
  EXPECT_EQ(s.checkValidString("**"), true);
  EXPECT_EQ(s.checkValidString("(**"), true);
  EXPECT_EQ(s.checkValidString("*"), true);
  EXPECT_EQ(s.checkValidString(")("), false);
  EXPECT_EQ(s.checkValidString(")"), false);
  EXPECT_EQ(s.checkValidString("(*))"), true);

  cout << s.SimplifyString(")") << endl;
  cout << s.SimplifyString(
              "()*((()(((((*))))((*()((*(())()(**)()()*))((((()**((("
              "))((()()(()(()()*)()))(()))))))*(((()()()())()")
       << endl;

  EXPECT_EQ(
      s.checkValidString("()*((()(((((*))))((*()((*(())()(**)()()*))((((()**((("
                         "))((()()(()(()()*)()))(()))))))*(((()()()())()"),
      false);
  EXPECT_EQ(
      s.checkValidString("*(((((((*))))((*((*(**)*))((((**(((((*))))))))*(("),
      false);
}
