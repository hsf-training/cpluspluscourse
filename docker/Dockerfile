
# Version 1
FROM gcc:9.3.0

# Ensure use of bash
SHELL ["/bin/bash","-c"]

# timezone
ENV TZ=Europe/Paris

# aptget : so to avoid debconf interactive questions
#RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
#ARG DEBIAN_FRONTEND=noninteractive

# Installations apt-get
RUN apt-get update \
&& apt-get install -y apt-utils  \
&& apt-get install -y make  \
&& rm -rf /var/lib/apt/lists/*

# update libraries cache
#RUN ldconfig

# start a shell by default
CMD bash

