# LeetCode Cpp

[![Travis Build Status][travis-image]][travis-url]

如果你也正在用C++进行刷Leetcode，但苦于每次写完代码无法都要自己写一大堆冗余代码进行测试和编译，本项目正式你想要的。

相比起Star最多的[Play-Leetcode](https://github.com/liuyubobobo/Play-Leetcode)项目，本项目主要使用Bazel进行构建的C++刷题项目，你只需要几个简单步骤即可完成构建、测试、覆盖率、持续集成等工作，让你更专注于刷题。

**欢迎大家能贡献测试用例，为更多的人提供便利。**

## 使用方法

0. `bazel build //...` 会创建构造所有的项目。
1. 在`src/`下创建`.h`代码文件，注意事项：
   - 命名方式`{补0的4位编号}_{题目URL中的Path}.h`，如第一题的命名为`0001_two-sum.h`
   - 文件开头需要`#include "base.h"`，该文件中包括引用常用库、树等结构模板定义、打印向量等辅助函数
   - 使用部分数据结构需要实例化模板，如`typedef base::TreeNode<int> Treenode;`
2. 在`test/`创建测试`.cc`文件，提示：
   - 命名方式`{补0的4位编号}_{题目URL中的Path}_test.cc`，如第一题的命名为`0001_two-sum_test.cc`
   - 需要`#include`对应的头文件
   - 使用googletest，不需写main函数
3. 在BUILD文件中，追加新完成的题号即可。
4. `bazel test //:0001_two-sum_test` 即编译并运行测试。测试结果会完整的打印到文件中，如果要打印完整的测试结果可以增加`--test_output=all`在test后作为选项

如果测试通过了，直接将`.h`中除了`#include`之后的代码贴入leetcode页面即可。

**`bazel-bin/no_test_source_files.txt`: 如果只创建了`.h`文件，没有`_test.cc`文件，会被列在这个文件中.**

## 更多便利

项目中的其他辅助脚本、配置、代码库，提供了更多的便利，可以点击对应功能直接跳转直介绍。

1. [格式化代码](#format-code)
2. [测试覆盖率](#coverage)
3. [持续集成](#continuous-integration)
4. [提供的辅助函数](#helper-function)

## Format Code

 脚本 tools/format.sh 是用于格式化`.h`、`.cc`、`BUILD`文件的工具，需要在项目根目录下执行：

```bash
cd leetcode-cpp
sh tools/format.sh
```


## Coverage

最新的代码覆盖率，请点击 [leetcode-cpp-coverage](https://panzhongxian.github.io/leetcode-cpp-coverage/leetcode-cpp/src/index.html).

如果自己需要做覆盖率测试，请详细越多以下内容：

Bazel 目前不能支持对高版本 GCC 9 的覆盖率测试和转换，目前[bazelbuild/bazel#9406](https://github.com/bazelbuild/bazel/issues/9406)该Issue还处于Open状态。

这里提供了一个 GCC 7 的编译环境，用于测试覆盖率。因此现需要构建一个Docker镜像：

```bash
cd leetcode-cpp
docker build --build-arg http_proxy=$http_proxy --build-arg https_proxy=$https_proxy -t ubuntu:18.04 tools/docker
```

构建完成后可以运行覆盖率测试的脚本：

```bash
docker run -v $PWD:/leetcode-cpp -e http_proxy=$http_proxy -e https_proxy=$https_proxy -t -i ubuntu:18.04 /bin/sh -c "cd leetcode-cpp && tools/coverage.sh"
```

生成的覆盖率报告将存放在`bazel-coverage`目录下，格式为HTML，形式如下：

![Coverage HTML](pic/lcov-coverage.png)

## Continuous Integration

本项目使用[Travis CI](https://travis-ci.org/)，每次Commit后，均会出发一次构建，会检查代码格式、编译、测试三个方面是否通过。

配置文件为根目录下的`.travis.yml`文件，感兴趣的同学可以点击这个图标 [![Travis Build Status][travis-image]][travis-url] 查看。

## Helper Functions

TODO： 完成说明






[travis-image]: https://travis-ci.org/panzhongxian/leetcode-cpp.svg?branch=master
[travis-url]: https://travis-ci.org/panzhongxian/leetcode-cpp


