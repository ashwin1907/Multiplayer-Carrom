carrom: main.o utilities.o table.o ./src/bot.cpp ./src/rules.cpp ./src/physics.cpp ./src/glui.cpp ./src/mouse.cpp
	@gcc utilities.o table.o main.o -lglut -lGLU -lglui -o carrom
main.o: main.cpp
	@gcc -c main.cpp
utilities.o:
	@gcc -c ./src/utilities.cpp
table.o:
	@gcc -c ./src/table.cpp
clean:
	@rm -rf *.o carrom

