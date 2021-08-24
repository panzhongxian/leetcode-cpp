set -e
set -x

# Limit memory.
# export BAZEL_OPTIONS="--local_resources=4096,2,1.0"

# Limit the amount of progress output. We can't use --noshow_progress because
# Travis terminates the build after 10 mins without output.
export BAZEL_OPTIONS="$BAZEL_OPTIONS --curses=no"

# Enable thread safety analysis (only works with clang).
if [[ "$TRAVIS_COMPILER" = "clang" ]]; then
  export BAZEL_OPTIONS="$BAZEL_OPTIONS --copt=-Werror=thread-safety --copt=-Werror=thread-safety-reference"
fi

export BAZEL_VERSION="4.1.0"

wget https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/bazel-${BAZEL_VERSION}-installer-${BAZEL_OS}-x86_64.sh
chmod +x bazel-${BAZEL_VERSION}-installer-${BAZEL_OS}-x86_64.sh
./bazel-${BAZEL_VERSION}-installer-${BAZEL_OS}-x86_64.sh --user
echo "build --disk_cache=$HOME/bazel-cache" > ~/.bazelrc
echo "build --experimental_strict_action_env" >> ~/.bazelrc
du -sk $HOME/bazel-cache || true
touch $HOME/start-time

bazel build $BAZEL_OPTIONS -k //...
bazel test $BAZEL_OPTIONS -k //... --test_tag_filters=-noci

set +e
# Travis doesn't restore atime, so update mtime of files accessed during build.
find $HOME/bazel-cache -type f -anewer $HOME/start-time -print0 | xargs -0 touch
# Clean up cache.
echo "Deleting $(find $HOME/bazel-cache -type f -mtime +7 | wc -l) old files."
find $HOME/bazel-cache -type f -mtime +7 -delete
du -sk $HOME/bazel-cache
