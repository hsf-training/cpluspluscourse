
# Version 1
FROM gcc:9.3.0

# Ensure use of bash
SHELL ["/bin/bash","-c"]

# timezone
ENV TZ=Europe/Paris

# aptget : so to avoid debconf interactive questions
#RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
#ARG DEBIAN_FRONTEND=noninteractive

# apt-get
RUN apt-get update \
&& apt-get install -y apt-utils  \
&& apt-get install -y build-essential  \
&& apt-get install -y cppcheck  \
&& apt-get install -y libc6-dbg gdb valgrind \
&& rm -rf /var/lib/apt/lists/*

# other
ENV PATH=${PATH}:.
ENV LD_LIBRARY_PATH=.

# start a shell by default
CMD bash

