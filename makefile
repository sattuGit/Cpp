CC=g++
CXXFLAGS=-std=c++11
TOPTARGETS = all clean
SUBDIRS = $(wildcard */.)
$(TOPTARGETS): $(SUBDIRS)
$(local): make -f makeLocal
$(SUBDIRS):
	$(MAKE) -C $@ #$(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)
