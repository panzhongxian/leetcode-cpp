## Build Docker

```bash
cd leetcode-cpp
docker build --build-arg http_proxy=$http_proxy --build-arg https_proxy=$https_proxy -t ubuntu:18.04 tools/docker
```

## Coverage

```bash
docker run -v $PWD:/leetcode-cpp -e http_proxy=$http_proxy -e https_proxy=$https_proxy -t -i ubuntu:18.04 /bin/sh -c "cd leetcode-cpp && tools/coverage.sh"
```

## Format Code

```bash


```
