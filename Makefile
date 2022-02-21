.PHONY: build

build:
	@-sh Meta/Build.sh;

clean:
	@-sh Meta/Clean.sh;

docker-up:
	@-docker compose up --build;

docker-connect:
	@-sh Meta/Docker/Connect.sh;

docker-down:
	@-docker compose down --rmi all;

meta:
	@-make -C Meta;

prepare: clean docker-down

rebuild:
	@-sh Meta/Rebuild.sh;