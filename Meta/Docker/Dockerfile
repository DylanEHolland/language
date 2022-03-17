FROM ubuntu:latest

ENV DEBIAN_FRONTEND noninteractive
RUN apt update
RUN apt install bash build-essential cmake -yq
COPY . /src/liz
RUN rm -rf Build
ENTRYPOINT [ "/bin/bash", "/src/liz/Meta/Docker/EnvironmentSetup.sh"]