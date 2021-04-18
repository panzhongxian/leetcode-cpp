# LeetCode Cpp

[![Travis Build Status][travis-image]][travis-url]

一个旨在让你更专注于写C++刷LeetCode题的辅助项目

项目使用 Bazel 构建的 C++ 刷题项目，通过几个简单步骤即可完成编译、测试，提供工具用于代码格式化、覆盖率报告、持续集成，还有额外的工具函数辅助创建测试用例。

如果你正使用 C++ 刷 LeetCode，但苦于每次写完代码无法都要自己写一大堆冗余代码进行测试和编译，本项目正是你想要的。

**欢迎大家能提Pull Request，贡献测试用例和其他工具，为更多的人提供便利。**



## 使用方法

只需三步，即可编译和测试自己待提交的代码：

1. 创建**代码文件 (`.h`文件)**，存到`src/`目录，就是用于提交到 LeetCode 页面的Solution实现代码。
2. 创建**测试文件 (`_test.cc`文件)**，存到`test/`目录。目前已经添加了80多道题目的测试文件，可以自己仿照添加，更欢迎提PR贡献到项目中。
3. 编译并运行测试`bazel test //:0001_two-sum_test`。

点击查看本项目题解的**覆盖率报告**，点击 [leetcode-cpp-coverage](https://panzhongxian.github.io/leetcode-cpp-coverage/leetcode-cpp/src/index.html)。如果要自己要生成覆盖率报告，参考下边覆盖率报告小节。

### 额外说明

- **`.h`文件的命名方式**需要遵循：`{补0的4位编号}_{题目URL中的Path}.h`，如第一题命名为`0001_two-sum.h`
- **`_test.cc`文件命名方式**需要遵循：`{补0的4位编号}_{题目URL中的Path}_test.cc`，如第一题的命名为`0001_two-sum_test.cc`

- 建议**.h**文件中include自己需要的头文件([Make header files self-sufficient](https://www.oreilly.com/library/view/c-coding-standards/0321113586/ch24.html))
- 测试**.cc**文件需要`#include "base.h"`，base.h中包括引用常用库、树等结构模板定义、打印向量等辅助函数
- 测试**.cc**文件使用 [GoogleTest](https://github.com/google/googletest)，不需写`main()`函数
- 如果要测试所有的题目，使用 `bazel test //...`

- **`.h`**文件如果需要使用`TreeNode`等数据结构，需要实例化模板，如`typedef base::TreeNode<int> Treenode;`
- 欲打印完整的测试结果可以增加`--test_output=all`在`bazel test`后作为选项

- 如果只创建了`.h`文件，而没有创建的`_test.cc`，待添加的测试文件列表会列到文件**`bazel-bin/no_test_source_files.txt`**中



## 格式化代码

 脚本 `tools/format.sh` 是用于格式化`.h`、`.cc`、`BUILD`文件的工具，需要在项目根目录下执行：

```bash
cd leetcode-cpp
sh tools/format.sh
```



## 覆盖率报告

Bazel 目前不能支持对高版本 GCC 9 的覆盖率测试和转换，目前[bazelbuild/bazel#9406](https://github.com/bazelbuild/bazel/issues/9406)该Issue还处于Open状态。

本项目中提供了一个 GCC 7 的编译环境，用于测试覆盖率。先需要构建一个Docker镜像：

```bash
cd leetcode-cpp
docker build --build-arg http_proxy=$http_proxy --build-arg https_proxy=$https_proxy -t ubuntu:18.04 tools/docker
```

构建完成后，可以运行覆盖率测试的脚本：

```bash
docker run -v $PWD:/leetcode-cpp -e http_proxy=$http_proxy -e https_proxy=$https_proxy -t -i ubuntu:18.04 /bin/sh -c "cd leetcode-cpp && tools/coverage.sh"
```

生成的覆盖率报告将存放在`bazel-coverage`目录下，格式为HTML，形式如下：

![Coverage HTML](pic/lcov-coverage.png)



## 持续集成

本项目使用[Travis CI](https://travis-ci.org/)，每次Commit后，均会出发一次构建，会检查代码格式、编译、测试三个方面是否通过。

配置文件为根目录下的`.travis.yml`文件，感兴趣的同学可以点击这个图标 [![Travis Build Status][travis-image]][travis-url] 查看。



## 辅助模板

LeetCode中部分题目需要输入ListNode、BiDirListNode、TreeNode等结构的指针，在构造测试用例中，使用`base.h`中的模板，可以快速的创建对应结构的用例。

使用下边的方式，可以创建对应ListNode结构的指针：

```c++
ListNode::Factory({1, 2, 6})
```

类似的，可以创建对应TreeNode结构的指针：

```c++
base::TreeNodeFactory<int>("[1,2,2,3,3,null,null,4,5]")
```

同时，**`.h`**文件需要实例化模板，如`typedef base::TreeNode<int> Treenode;`，上边"额外说明"中也有提到。




[travis-image]: https://travis-ci.org/panzhongxian/leetcode-cpp.svg?branch=master
[travis-url]: https://travis-ci.org/panzhongxian/leetcode-cpp


