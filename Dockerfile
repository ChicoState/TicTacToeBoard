FROM ubuntu:xenial
MAINTAINER Kevin Buffardi (kbuffardi@csuchico.edu)
LABEL title="Unit Testing CPP"
LABEL version=0.1
ENV GTEST_REPO=/googletest
ENV GTEST_DIR=${GTEST_REPO}/googletest
ENV CXXFLAGS=-std=c++11
ENV WORKDIR=/usr/src
WORKDIR /usr/src

# Install dependencies
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
            build-essential \
            g++ \
            cmake \
            git-all

# Setup GoogleTest
RUN git clone https://github.com/google/googletest ${GTEST_REPO} && \
    mkdir ${GTEST_REPO}/build && \
    cd ${GTEST_REPO}/build && \
    cmake .. -DBUILD_GMOCK=OFF && \
    make && \
    make install && \
    cd ${WORKDIR}

# Build and run tests
CMD ["sh","-c","sed -i -e 's/\r$//' test_runner.sh; ${WORKDIR}/test_runner.sh; gcov -rbc *.cpp"]
