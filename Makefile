CXX = g++
CXXFLAGS = -std=c++17 -Wall -Ilib/include
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = \
    lib/src/game.cpp \
    lib/src/player.cpp \
    main/src/main.cpp

OBJ = $(SRC:.cpp=.o)

BIN = lvdlm

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(BIN)
