.PHONY: cmake clean cacheclean distclean archive archclean handin handin-% test

BINDIR=build/bin
RUNFILE=$(BINDIR)/lab          # make run 的执行文件
ARCHPFX=xxxxxxxxxx-xxx         # handin的前缀

MAKE+=-j --no-print-directory  # 多线程make，不显示make进入文件夹的信息

all: build
	$(MAKE) -C build

run: all
	$(RUNFILE)

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