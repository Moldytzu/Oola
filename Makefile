.PHONY=game

all:
	$(MAKE) -s -C engine -j$(shell nproc)
	$(MAKE) -s -C game run