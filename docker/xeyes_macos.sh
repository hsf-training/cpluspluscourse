#!/bin/bash

export DISPLAY=${MYIP}:0
xhost + ${MYIP}

docker run -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix:rw gns3/xeyes
