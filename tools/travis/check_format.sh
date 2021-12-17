set -e
set -x

# Install buildifier.
mkdir -p $HOME/bin
wget -O $HOME/bin/buildifier https://github.com/bazelbuild/buildtools/releases/download/2.2.1/buildifier
chmod +x $HOME/bin/buildifier

# Install cmake-format.
#pyenv global 3.7.1
pip3 install --user 'cmake_format>=0.5.2'
# Check format.
tools/format.sh
