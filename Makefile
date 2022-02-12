
INCLUDE = -I ./include/

FLAGS = -Wall -Wextra

all:
	g++ $(FLAGS) -o jam $(INCLUDE) src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system

run:
	$(MAKE) all
	./jam
