#!/bin/bash

SCRIPT_NAME=${BASH_SOURCE[0]}
SCRIPT_DIR=`dirname ${SCRIPT_NAME}`
cd ${SCRIPT_DIR}

docker build -f Dockerfile -t `cat name.txt` .
# --force-rm --no-cache