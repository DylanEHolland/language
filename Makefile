.PHONY: build test-all

build:
	@-sh Meta/Build.sh;

clean:
	@-sh Meta/Clean.sh;

docker-up:
	@-docker compose up --build;

docker-clean:
	@-sh Meta/Docker/Clean.sh;

docker-connect:
	@-sh Meta/Docker/Connect.sh;

docker-down:
	@-docker compose down --rmi all;

meta:
	@-make -C Meta;

prepare: clean docker-down

rebuild:
	@-sh Meta/Rebuild.sh;

test-local:
	@-sh Meta/Runtest.sh all

test-with-docker: docker-up

test-all: test-local test-with-docker
