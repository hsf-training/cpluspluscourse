#!/bin/bash

export DISPLAY=${MYIP}:0
xhost + ${MYIP}

docker run -e DISPLAY=$DISPLAY gns3/xeyes
