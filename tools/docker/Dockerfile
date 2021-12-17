FROM ubuntu:bionic

RUN apt-get update && apt install -y build-essential manpages-dev wget unzip git default-jre default-jdk lcov python3-pip python3.7 clang-format

RUN cd /tmp/ && wget https://github.com/bazelbuild/bazel/releases/download/4.1.0/bazel-4.1.0-installer-linux-x86_64.sh && chmod +x bazel*sh && ./bazel*sh && rm ./bazel*

RUN python3.7 -m pip install pip

CMD ["/bin/bash"]
