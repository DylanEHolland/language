FROM ubuntu:latest

RUN apt update
ENV DEBIAN_FRONTEND noninteractive
RUN apt install bash build-essential cmake -yq
COPY . /src/liz
RUN rm -rf Build
ENTRYPOINT [ "/bin/bash", "/src/liz/Meta/Docker/EnvironmentSetup.sh"]