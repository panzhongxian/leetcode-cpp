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

cc_binary(
    name = "2_add_two_numbers",
    srcs = glob(["0002_*.cc"]),
    local_defines = ["LC_TEST"],
    deps = [":base"],
)

cc_binary(
    name = "2_add_two_numbers_bm",
    srcs = glob(["0002_*.cc"]),
    local_defines = ["LC_BM"],
    deps = [":base"],
)

cc_binary(
    name = "11_container_with_most_water",
    srcs = glob(["0011_*.cc"]),
    local_defines = ["LC_TEST"],
    deps = [":base"],
)

cc_binary(
    name = "11_container_with_most_water_bm",
    srcs = glob(["0011_*.cc"]),
    local_defines = ["LC_BM"],
    deps = [":base"],
)

cc_binary(
    name = "15_three_sum",
    srcs = glob(["0015_*.cc"]),
    local_defines = ["LC_TEST"],
    deps = [":base"],
)

cc_binary(
    name = "15_three_sum_bm",
    srcs = glob(["0015_*.cc"]),
    local_defines = ["LC_BM"],
    deps = [":base"],
)

cc_binary(
    name = "18_four_sum",
    srcs = glob(["0018_*.cc"]),
    local_defines = ["LC_TEST"],
    deps = [":base"],
)

cc_binary(
    name = "18_four_sum_bm",
    srcs = glob(["0018_*.cc"]),
    local_defines = ["LC_BM"],
    deps = [":base"],
)
