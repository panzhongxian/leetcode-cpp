if [[ ! -e tools/format.sh ]]; then
  echo "This tool must be run from the topmost directory." >&2
  exit 1
fi

set -e

usage()
{
    echo "usage: format.sh [--disable-sed-check] [--disable-tools-check]"
}

sed_check=y
tools_check=y

while [[ "$1" != "" ]]; do
    case $1 in
        --disable-sed-check )   sed_check=n
                                ;;
        --disable-tools-check ) tools_check=n
                                ;;
        -h | --help )           usage
                                exit
                                ;;
        * )                     usage
                                exit 1
    esac
    shift
done

FIND="find . -name .git -prune -o -name pic -prune -o -name _deps -prune -o -name .build -prune -o"

if [[ "$sed_check" == "y" ]]; then
  # No CRLF line endings.
  sed -i 's/\r$//' $($FIND -type f -print)
  # No trailing spaces.
  sed -i 's/ \+$//' $($FIND -type f -print)
fi

if [[ "$tools_check" == "y" ]]; then
  # For easier debugging: print the version because it affects the formatting.
  CMD=clang-format
  if which clang-format-7 >/dev/null; then
    CMD=clang-format-7
  fi
  $CMD -version
  $CMD -i -style=file \
    $($FIND -name '*.cc' -print -o -name '*.h' -print)
  if which buildifier >/dev/null; then
    echo "Running buildifier."
    buildifier $($FIND -name WORKSPACE -print -o -name BUILD -print -o \
      -name '*.bzl' -print)
  else
    echo "Can't find buildifier. It can be installed with:"
    echo "  go get github.com/bazelbuild/buildtools/buildifier"
  fi
fi

CHANGED="$(git ls-files --modified)"
if [[ ! -z "$CHANGED" ]]; then
  echo "The following files have changes:"
  echo "$CHANGED"
  exit 1
else
  echo "No changes."
fi

if [[ "$sed_check" != "y" || "$tools_check" != "y" ]]; then
  echo "All checks must run to succeed."
  exit 1
fi
