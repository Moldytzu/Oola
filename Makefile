.PHONY=game

all:
	$(MAKE) -C engine -j$(shell nproc)
	$(MAKE) -C game run

clean:
	$(MAKE) -C engine clean
	$(MAKE) -C game clean