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


