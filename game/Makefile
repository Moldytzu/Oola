rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
reverse = $(if $(1),$(call reverse,$(wordlist 2,$(words $(1)),$(1)))) $(firstword $(1))

SRCDIR := src
OBJDIR := obj
BINDIR := bin

CPP = g++
AR = ar
LIB = ../engine/bin/oola.a
EXE = $(BINDIR)/game.bin

CPPFLAGS = -Iinc -I../engine/inc -g -std=c++20 -Werror -Wall -Wpedantic -Wextra -fno-exceptions

SRC = $(call rwildcard,$(SRCDIR),*.cpp)  
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

run: game
	./$(EXE)

game: $(OBJS)
	@ mkdir -p $(BINDIR)
	$(CPP) $(LIB) $(OBJS) -lSDL2main -lSDL2 -lGL -lGLU -o $(EXE)

clean:
	rm -f $(OBJS) $(EXE)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@ mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -c $^ -o $@

.PHONY: lib