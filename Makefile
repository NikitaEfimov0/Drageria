F = -lsfml-graphics -lsfml-window -lsfml-system
S = -std=c++20



all: game
game: Main.o Arbitrator.o  Board.o BoardGet.o Cell.o BoardDraw.o HeroDrow.o Hero.o GetPathToTexture.o FireBallDraw.o Archer.o ArcherDraw.o Worm.o WormDraw.o Dragon.o DragonDraw.o HealToolDraw.o PoisonToolDraw.o SuperHealToolDraw.o;
	g++ $(S) Main.o Arbitrator.o BoardGet.o Board.o Cell.o BoardDraw.o HeroDraw.o Hero.o GetPathToTexture.o FireBallDraw.o Archer.o ArcherDraw.o Worm.o WormDraw.o Dragon.o DragonDraw.o HealToolDraw.o PoisonToolDraw.o SuperHealToolDraw.o -o game $(F) && make -f Makefile clean
Main.o: ; g++ $(S) -g -c Main.cpp $(F)
Arbitrator.o: ; g++ $(S) -g -c Arbitrator.cpp $(F)
Board.o: ; g++ $(S) -g -c Board.cpp $(F)
BoardGet.o: ; g++ $(S) -g -c BoardGet.cpp $(F)
Cell.o: ; g++ $(S) -g -c Cell.cpp $(F)
BoardDraw.o: ; g++ $(S) -g -c BoardDraw.cpp $(F)
HeroDrow.o: ; g++ $(S) -g -c HeroDraw.cpp $(F)
Hero.o: ; g++ $(S) -g -c Hero.cpp $(F)
GetPathToTexture.o: ; g++ $(S) -g -c GetPathToTexture.cpp $(F)
FireBallDraw.o: ; g++ $(S) -g -c FireBallDraw.cpp $(F)
Archer.o: ; g++ $(S) -g -c Archer.cpp $(F)
ArcherDraw.o: ; g++ $(S) -g -c ArcherDraw.cpp $(F)
Worm.o: ; g++ $(S) -g -c Worm.cpp $(F)
WormDraw.o: ; g++ $(S) -g -c WormDraw.cpp $(F)
Dragon.o: ; g++ $(S) -g -c Dragon.cpp $(F)
DragonDraw.o: ; g++ $(S) -g -c DragonDraw.cpp $(F)
HealToolDraw.o: ; g++ $(S) -g -c HealToolDraw.cpp $(F)
PoisonToolDraw.o: ; g++ $(S) -g -c PoisonToolDraw.cpp $(F)
SuperHealToolDraw.o: ; g++ $(S) -g -c SuperHealToolDraw.cpp $(F)
clean: ; rm -rf *.o