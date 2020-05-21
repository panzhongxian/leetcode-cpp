# Inspired by the answer here:
# <How to apply a macro to an array of names of targets in bazel?>
# https://stackoverflow.com/questions/48510907/how-to-apply-a-macro-to-an-array-of-names-of-targets-in-bazel/48511351

# https://jayconrod.com/posts/98/migrating-to-bazel--part-2

def _xxxx_rule_impl(ctx):
    pass

def lc_deps():
    native.cc_library(
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

def lc_gen(index):
    index = str(int(index))
    file_pattern = (4 - len(index)) * "0" + index + "_*"
    target_name = native.glob([file_pattern + ".h"])[0].rstrip(".h")
    native.cc_library(
        name = target_name,
        srcs = [target_name + ".h"],
        deps = [
            "@com_google_googletest//:gtest_main",
            ":base",
        ],
    )

    test_file_name = "test/" + target_name + "_test.cc"
    if not len(native.glob([test_file_name])):
        return

    native.cc_test(
        name = target_name + "_test",
        srcs = [test_file_name],
        deps = [
            "//:" + target_name,
        ],
    )
