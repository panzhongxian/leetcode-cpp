workspace(name = "panzhongxian_leetcode")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# GoogleTest framework.
# Only needed for tests, not to build the OpenCensus library.
http_archive(
    name = "com_google_googletest",
    strip_prefix = "googletest-master",
    urls = ["https://github.com/google/googletest/archive/master.zip"],
)

# Google Benchmark library.
# Only needed for benchmarks, not to build the OpenCensus library.
http_archive(
    name = "com_github_google_benchmark",
    strip_prefix = "benchmark-main",
    urls = ["https://github.com/google/benchmark/archive/main.zip"],
)

# Depend on Abseil.
http_archive(
    name = "com_google_absl",
    strip_prefix = "abseil-cpp-master",
    urls = ["https://github.com/abseil/abseil-cpp/archive/master.zip"],
)
