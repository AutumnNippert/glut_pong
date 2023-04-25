CXX=g++
FLAGS=-lGL -lglut -lncurses

OBJECTS=GameObject.o Paddle.o Ball.o Boundary.o game.o
EXES=game

all: $(EXES)

# Compile all executables
game: $(OBJECTS)
	$(CXX) $(OBJECTS) -o game $(FLAGS)

# Compile all object files
# Dont ask me how this works, but it does. Thanks github copilot
%.o: %.cpp %.h
	$(CXX) -c $< -o $@

clean:
	rm -f *.o $(EXES)
