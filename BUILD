cc_library(
    name = "base",
    srcs = [
        "base.cc",
        "base.h",
    ],
    deps = [
        "@com_github_google_benchmark//:benchmark",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_binary(
    name = "1_two_sum",
    srcs = ["0001_two_sum.cc"],
    local_defines = ["LC_TEST"],
    deps = [":base"],
)

cc_binary(
    name = "1_two_sum_bm",
    srcs = ["0001_two_sum.cc"],
    local_defines = ["LC_BM"],
    deps = [":base"],
)
