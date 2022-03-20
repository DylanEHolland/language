#!/usr/bin/env bash
. Meta/Common.sh

echo "[Build/Docker/Clean.sh]"
make docker-down &> /dev/null && echo "[make] docker-down"

echo "[docker] Killing all docker processes with liz_ in the name";

already_removed="";

for docker_process_data in `docker ps -a | grep "/src/liz" | awk '{print $1 "|" $2}'`; do
    container_id=`echo $docker_process_data | cut -d "|" -f 1`
    image_id=`echo $docker_process_data | cut -d "|" -f 2`

    TRY_TO_REMOVE=true;
    for removed in $already_removed; do
        [ "$removed" = "$image_id" ] || already_removed+="$image_id ";
        [ "$removed" = "$image_id" ] || TRY_TO_REMOVE=false
    done;
    
    if $TRY_TO_REMOVE; then
        echo "[docker] Trying to remove image: " $image_id;
        docker image rm $image_id --force;
    fi;

    echo "[docker] Trying to remove container: " $container_id;
    docker container rm $container_id --force;
    
done;

echo "[docker] Dropping images with liz_ in the name..."
for img in `docker image ls -a | grep "liz_" | awk '{print $1}'`; do
    docker image rm $img --force;
done;

echo "[docker] Dropping containers with liz_ in the name..."
for container in `docker container ls -a | grep "liz_" | awk '{print $1}'`; do
    docker container rm $container --force;
done;

echo "[docker] Dropping volumes with liz_ in the name..."
for volume in `docker volume ls | grep "liz_" | awk '{print $2}'`; do
    docker volume rm $volume --force;
done;
