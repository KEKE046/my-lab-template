.PHONY: cmake clean cacheclean distclean archive archclean handin handin-% test

BINDIR=build/bin
ARCHPFX=xxxxxxxxxx-xxx
MAKE+=-j --no-print-directory

all: build
	$(MAKE) -C build

run: all
	$(BINDIR)/lab

test: all
	cd build && ctest

config: build
	ccmake -S . -B build

rebuild: cacheclean all

archclean:
	rm -rf $(ARCHPFX)*

clean: archclean
	$(MAKE) -C build clean

cacheclean: archclean
	rm -rf build/CMakeCache.txt

distclean: archclean
	rm -rf build

build:
	mkdir build
	cmake -S . -B build

handin:
	git archive HEAD -o $(ARCHPFX).tar.gz

handin-%:
	git archive HEAD -o $(ARCHPFX)-$*.tar.gz