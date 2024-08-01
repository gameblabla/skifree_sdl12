PRGNAME     = free.elf
CC			= gcc

SRCDIR		= ./src
VPATH		= $(SRCDIR)
SRC_C		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
SRC_CP		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cpp))
OBJ_C		= $(notdir $(patsubst %.c, %.o, $(SRC_C)))
OBJ_CP		= $(notdir $(patsubst %.cpp, %.o, $(SRC_CP)))
OBJS		= $(OBJ_C) $(OBJ_CP)

CFLAGS		= -O0 -g3
CFLAGS		+= -DLSB_FIRST -std=gnu99 -DALIGN_DWORD -DNOYUV -I/usr/include/SDL
CFLAGS		+= -Isource -Isource/cpu_cores/$(Z80_CORE) -Isource/scalers -Isource/ports/$(PORT) -I./source/sound -Isource/unzip -Isource/sdl -Isource/sound/$(SOUND_ENGINE) -Isource/sound_output

CFLAGS		+= -Isrc -Iresources

ifeq ($(PROFILE), YES)
CFLAGS 		+= -fprofile-generate=./
else ifeq ($(PROFILE), APPLY)
CFLAGS		+= -fprofile-use -fbranch-probabilities
endif
LDFLAGS     = -lc -lgcc -lm -lSDL -lSDL_ttf -Wl,--as-needed -Wl,--gc-sections -flto

# Rules to make executable
$(PRGNAME): $(OBJS)  
	$(CC) $(CFLAGS) -o $(PRGNAME) $^ $(LDFLAGS)

$(OBJ_C) : %.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(PRGNAME) *.o
