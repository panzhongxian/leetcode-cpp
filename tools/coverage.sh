#!/usr/bin/env bash
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Builds a coverage report.

if [[ ! -e tools/coverage.sh ]]; then
  echo "This tool must be run from the topmost directory." >&2
  exit 1
fi

if ! which genhtml >/dev/null; then
  echo "Install lcov to get the genhtml program."
  exit 1
fi

set -e
OUTDIR=bazel-coverage

bazel --output_base=/tmp/bazel_output coverage --combined_report=lcov //:all --javabase=@bazel_tools//tools/jdk:remote_jdk11
genhtml --show-details --legend --output-directory $OUTDIR \
  $(find bazel-out/ -name coverage.dat)
ls -l $OUTDIR/index.html
