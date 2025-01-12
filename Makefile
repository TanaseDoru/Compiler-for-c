COMPILER = gcc
BISON_FLAGS = -d -v 

all: source

source: source.l source.y VTR.h SM.h functionHandler.h
	bison $(BISON_FLAGS) source.y
	flex -o source.yy.c source.l
	$(COMPILER) source.tab.c source.yy.c -o source
