# LeetCode Cpp

[![Travis Build Status][travis-image]][travis-url]

# Summary

## 数字翻转

Tips:

1. 需要考虑末尾为0的特殊情况
2. 需要考虑数字长度为奇数和偶数的不同情况
3. 需要考虑转换前数字的有效性
4. 需要考虑转换后数字的范围
5. 不能将转换后的数字做有效性判断，而应该在转换前


## 常见错误

### 类型转换
```c++
size_t i = 0;
i < s.size() - 1
```
当s.size() = 0时，这个就成立了。

所以应该改用
```c++
size_t i = 0;
i + 1< s.size()
```
或者将`s.size()`转换成`signed int`


###

某些编译器无法将pow等math库里边的函数作为constexpr的结果。

```
0007_reverse_integer.cc:2:15: error: constexpr variable 'upper_limit' must be initialized by a constant expression
constexpr int upper_limit = pow(2, 31) - 1;  // 2147483647
              ^             ~~~~~~~~~~~~~~
/usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/cmath:437:14: note: non-constexpr function 'pow' cannot be used in a constant expression
      return pow(__type(__x), __type(__y));
             ^
0007_reverse_integer.cc:2:29: note: in call to 'pow(2, 31)'
constexpr int upper_limit = pow(2, 31) - 1;  // 2147483647
                            ^
/usr/include/x86_64-linux-gnu/bits/mathcalls.h:153:17: note: declared here
__MATHCALL_VEC (pow,, (_Mdouble_ __x, _Mdouble_ __y));
```


[travis-image]: https://travis-ci.org/panzhongxian/leetcode-cpp.svg?branch=master
[travis-url]: https://travis-ci.org/panzhongxian/leetcode-cpp

