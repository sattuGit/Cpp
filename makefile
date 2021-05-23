CC=g++
CXXFLAGS=-std=c++11
TOPTARGETS = all clean
SUBDIRS = $(wildcard */.)
local=makeLocal
$(TOPTARGETS): $(local) $(SUBDIRS)
$(local): make -f makeLocal
$(SUBDIRS):
	$(MAKE) -C $@ #$(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS) make -f makeLocal clean

