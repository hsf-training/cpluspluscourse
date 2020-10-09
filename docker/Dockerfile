
# Version 1
FROM gcc:9.3.0

# Ensure use of bash
SHELL ["/bin/bash","-c"]

# timezone
ENV TZ=Europe/Paris

# apt-get preparation
RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
&& apt-get install -y apt-utils

# c++ tools
RUN apt-get install -y build-essential  \
&& apt-get install -y cppcheck  \
&& apt-get install -y libc6-dbg gdb \
&& apt-get install -y binutils graphviz \
&& apt-get install -y valgrind kcachegrind

# python
RUN apt-get install -y python-backports.functools-lru-cache \
&& apt-get install -y python-tk \
&& apt-get install -y python-pip
RUN pip install numpy
RUN pip install matplotlib

# other
RUN rm -rf /var/lib/apt/lists/*
ENV PATH=${PATH}:.
ENV LD_LIBRARY_PATH=.

# start a shell by default
CMD bash

