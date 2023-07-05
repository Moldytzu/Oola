.PHONY=game

all:
	$(MAKE) -C engine -j$(shell nproc)
	$(MAKE) -C game run