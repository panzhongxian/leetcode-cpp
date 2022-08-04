cd $(dirname $0)/..
REPO_ROOT=$(pwd)

docker build -t ltcd_cpp_iwyu tools/iwyu

docker run \
  -e TEST="$TEST" \
  -e CHANGED_FILES="$CHANGED_FILES" \
  -e IWYU_ROOT="/local-code" \
  --rm=true \
  -v "${REPO_ROOT}":/local-code \
  -v "${HOME/.cache/bazel}":"${HOME/.cache/bazel}" \
  --user "$(id -u):$(id -g)" \
  -t ltcd_cpp_iwyu /iwyu.sh "$@"


