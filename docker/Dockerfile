
# Version 2, en Python3

FROM gcc:9.3.0

# Ensure use of bash

SHELL ["/bin/bash","-c"]

# Timezone

ENV TZ=Europe/Paris

# Apt-get General Preparation

RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
&& apt-get install -y apt-utils

# C++ Tools

RUN apt-get install -y build-essential  \
&& apt-get install -y cppcheck  \
&& apt-get install -y libc6-dbg gdb \
&& apt-get install -y binutils graphviz \
&& apt-get install -y valgrind kcachegrind

RUN echo "set auto-load safe-path /" > /root/.gdbinit

# Python
# It seems I MUST say 3.7 for dev :s

RUN apt-get install -y python3.7 \
&& apt-get install -y python3.7-dev \
&& apt-get install -y python3-pip \
&& apt-get install -y python3-tk

RUN pip3 install numpy
RUN pip3 install matplotlib

# Other

RUN rm -rf /var/lib/apt/lists/*
ENV PATH=${PATH}:.
ENV LD_LIBRARY_PATH=.

# Start a shell by default

CMD bash

