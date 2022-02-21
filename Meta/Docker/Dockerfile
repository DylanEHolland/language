FROM ubuntu:latest

RUN mkdir -pv /src/liz
COPY . /src/liz
ENTRYPOINT [ "/bin/bash", "/src/liz/Meta/Docker/EnvironmentSetup.sh" ]