FROM ubuntu:bionic

RUN apt update &&  apt install -y build-essential manpages-dev wget unzip git default-jre default-jdk lcov

RUN cd /tmp/ && wget https://github.com/bazelbuild/bazel/releases/download/3.1.0/bazel-3.1.0-installer-linux-x86_64.sh && chmod +x bazel*sh && ./bazel*sh && rm ./bazel*

CMD ["/bin/bash"]
