#!/usr/bin/env bash
. Meta/Common.sh;

DOCKER_IMAGE_NAME=`docker image ls | grep liz_test_runner | grep -v CREATED | awk '{print $1;}'`;
docker run -it $DOCKER_IMAGE_NAME $@;