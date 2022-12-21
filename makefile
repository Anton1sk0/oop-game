OBJS	= main.o Avatar.o Earth.o Entity.o Game.o Map.o Position.o Potion.o Terrain.o Vampire.o VampireAvatar.o Warrior.o Water.o Werewolf.o WerewolfAvatar.o Woods.o
SOURCE	= main.cpp Avatar.cpp Earth.cpp Entity.cpp Game.cpp Map.cpp Position.cpp Potion.cpp Terrain.cpp Vampire.cpp VampireAvatar.cpp Warrior.cpp Water.cpp Werewolf.cpp WerewolfAvatar.cpp Woods.cpp
HEADER	= Avatar.h Earth.h Entity.h Game.h Map.h Position.h Potion.h Terrain.h Vampire.h VampireAvatar.h Warrior.h Water.h Werewolf.h WerewolfAvatar.h Woods.h Tags.h
OUT	= GameWV.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

Avatar.o: Avatar.cpp
	$(CC) $(FLAGS) Avatar.cpp 

Earth.o: Earth.cpp
	$(CC) $(FLAGS) Earth.cpp 

Entity.o: Entity.cpp
	$(CC) $(FLAGS) Entity.cpp 

Game.o: Game.cpp
	$(CC) $(FLAGS) Game.cpp 

Map.o: Map.cpp
	$(CC) $(FLAGS) Map.cpp 

Position.o: Position.cpp
	$(CC) $(FLAGS) Position.cpp 

Potion.o: Potion.cpp
	$(CC) $(FLAGS) Potion.cpp 

Terrain.o: Terrain.cpp
	$(CC) $(FLAGS) Terrain.cpp 

Vampire.o: Vampire.cpp
	$(CC) $(FLAGS) Vampire.cpp 

VampireAvatar.o: VampireAvatar.cpp
	$(CC) $(FLAGS) VampireAvatar.cpp 

Warrior.o: Warrior.cpp
	$(CC) $(FLAGS) Warrior.cpp 

Water.o: Water.cpp
	$(CC) $(FLAGS) Water.cpp 

Werewolf.o: Werewolf.cpp
	$(CC) $(FLAGS) Werewolf.cpp 

WerewolfAvatar.o: WerewolfAvatar.cpp
	$(CC) $(FLAGS) WerewolfAvatar.cpp 

Woods.o: Woods.cpp
	$(CC) $(FLAGS) Woods.cpp 


clean:
	rm -f $(OBJS) $(OUT)