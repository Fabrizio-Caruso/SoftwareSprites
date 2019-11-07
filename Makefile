# Makefile 
CC65_PATH ?=
SOURCE_PATH ?= ./src
DEMOS_PATH ?= ./demos
BUILD_PATH ?= ./build

MYCCFLAGS=-t c16 -O -Cl

ifneq ($(COMSPEC),)
DO_WIN:=1
endif
ifneq ($(ComSpec),)
DO_WIN:=1
endif 

ifeq ($(DO_WIN),1)
EXEEXT = .exe
endif

ifeq ($(DO_WIN),1)
COMPILEDEXT = .exe
else
COMPILEDEXT = .out
endif

MYCC65 ?= cc65$(EXEEXT) $(INCLUDE_OPTS) 
MYCL65 ?= cl65$(EXEEXT) $(INCLUDE_OPTS) 

# Full Kernal with: --asm-define STANDARD_IRQ=1 


test_one_sprite:
	$(CC65_PATH)$(MYCL65) $(MYCCFLAGS) $(MYCFG) \
	$(SOURCE_PATH)/software_sprites.c \
	$(DEMOS_PATH)/test_one_sprite.c \
	-o $(BUILD_PATH)/test_one_sprite.prg


####################################################
clean:
	rm -rf *.prg
	rm -rf $(SOURCE_PATH)/*.o
	rm -rf $(DEMOS_PATH)/*.o
	rm -rf ./build/*
	rm -rf main.s

   
all: \
    test_one_sprite




