#!/bin/bash

SCRIPT_NAME=${BASH_SOURCE[0]}
SCRIPT_DIR=`dirname ${SCRIPT_NAME}`

export DISPLAY=${MYIP}:0
xhost + ${MYIP}

docker run -e DISPLAY=$DISPLAY -it --rm -v $PWD:/work -w /work `cat ${SCRIPT_DIR}/name.txt` $*
