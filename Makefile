CC = g++
CFLAGS = -Wall -std=c++98
LIBS = -lncurses -lpanel 
OBJECTS = toolkit.o basetile.o baseactor.o basemessage.o basesystem.o main.o game.o io.o ui.o player.o messages.o scene.o

all : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o main

%.o : %.c %.h
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f *.o main *.gch
