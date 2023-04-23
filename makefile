CC=g++
FLAGS=-lGL -lglut -lncurses

HEADERS=GameObjects.h
OBJECTS=GameObject.o Paddle.o Ball.o Boundary.o
EXES=game

all: $(EXES)

# Compile all executables
game: $(OBJECTS) $(HEADERS)
	$(CC) game.cpp -o game $(FLAGS)

# Compile all object files
# Dont ask me how this works, but it does. Thanks github copilot
%.o: %.cpp $(HEADERS)
	$(CC) -c $< -o $@

clean:
	rm -f *.o $(EXES)