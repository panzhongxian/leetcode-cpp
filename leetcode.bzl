# Inspired by the answer here:
# <How to apply a macro to an array of names of targets in bazel?>
# https://stackoverflow.com/questions/48510907/how-to-apply-a-macro-to-an-array-of-names-of-targets-in-bazel/48511351
# https://jayconrod.com/posts/98/migrating-to-bazel--part-2

def _export_file(ctx):
    out = ctx.actions.declare_file(ctx.attr.name + ".txt")
    ctx.actions.write(out, ctx.attr.content)

    #ctx.actions.write(out, ctx.attr.name)
    return DefaultInfo(files = depset([out]))

export_file = rule(
    _export_file,
    attrs = {
        "content": attr.string(),
    },
)

def lc_deps():
    native.cc_library(
        name = "base",
        srcs = [
            "utils/base.cc",
        ],
        visibility = ["//visibility:public"],
        strip_include_prefix = "utils",
        hdrs = [
            "utils/base.h",
            "utils/nested_integer.h",
        ],
        deps = [
            "@com_github_google_benchmark//:benchmark",
            "@com_google_googletest//:gtest_main",
            "@com_google_absl//absl/strings",
        ],
    )

def lc_gen():
    test_files = native.glob(["test/*_test.cc"])
    no_source_test_files = []
    for test_file in test_files:
        target_name = test_file[5:-8]
        source_file = native.glob(["src/" + target_name + ".h"])
        if len(source_file) == 0:
            no_source_test_files.append("src/" + target_name + ".h")
        elif len(source_file) == 1:
            native.cc_library(
                name = target_name,
                srcs = ["src/" + target_name + ".h"],
                deps = [
                    "@com_google_googletest//:gtest_main",
                    ":base",
                ],
                visibility = ["//visibility:public"],
            )

            native.cc_test(
                name = target_name + "_test",
                srcs = [test_file],
                copts = ["-Isrc/"],
                deps = [
                    "//:" + target_name,
                ],
            )

    for no_source_test_file in no_source_test_files:
        print("lack of source file: " + no_source_test_file)

    source_files = native.glob(["src/*.h"], ["src/0000_*"])
    no_test_source_files = []
    for source_file in source_files:
        target_name = source_file[4:-2]
        test_file = "test/" + target_name + "_test.cc"

        if len(native.glob([test_file])) < 1:
            no_test_source_files.append(test_file)

    if no_test_source_files:
        export_file(
            name = "no_test_source_files",
            content = "\n".join(no_test_source_files),
        )
