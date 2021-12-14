F = -lsfml-graphics -lsfml-window -lsfml-system
S = -std=c++20



all: game
game: Main.o Arbitrator.o  Board.o BoardGet.o Cell.o BoardDraw.o HeroDrow.o Hero.o GetPathToTexture.o FireBallDraw.o Archer.o ArcherDraw.o Worm.o WormDraw.o Dragon.o DragonDraw.o HealToolDraw.o PoisonToolDraw.o SuperHealToolDraw.o;
	g++ $(S) Main.o Arbitrator.o BoardGet.o Board.o Cell.o BoardDraw.o HeroDraw.o Hero.o GetPathToTexture.o FireBallDraw.o Archer.o ArcherDraw.o Worm.o WormDraw.o Dragon.o DragonDraw.o HealToolDraw.o PoisonToolDraw.o SuperHealToolDraw.o -o game $(F) -Wno-deprecated-declarations && make -f Makefile clean
Main.o: ; g++ $(S) -g -c ./MainFiles/Main.cpp $(F)
Arbitrator.o: ; g++ $(S) -g -c ./MainFiles/Arbitrator.cpp $(F)
Board.o: ; g++ $(S) -g -c ./Board/Board.cpp $(F)
BoardGet.o: ; g++ $(S) -g -c ./Board/BoardGet.cpp $(F)
Cell.o: ; g++ $(S) -g -c ./Board/Cell.cpp $(F)
BoardDraw.o: ; g++ $(S) -g -c ./Board/BoardDraw.cpp $(F)
HeroDrow.o: ; g++ $(S) -g -c ./ObjectsDraw/HeroDraw.cpp $(F)
Hero.o: ; g++ $(S) -g -c ./Objects/Hero.cpp $(F)
GetPathToTexture.o: ; g++ $(S) -g -c ./MainFiles/GetPathToTexture.cpp $(F)
FireBallDraw.o: ; g++ $(S) -g -c ./ObjectsDraw/FireBallDraw.cpp $(F)
Archer.o: ; g++ $(S) -g -c ./Objects/Archer.cpp $(F)
ArcherDraw.o: ; g++ $(S) -g -c ./ObjectsDraw/ArcherDraw.cpp $(F)
Worm.o: ; g++ $(S) -g -c ./Objects/Worm.cpp $(F)
WormDraw.o: ; g++ $(S) -g -c ./ObjectsDraw/WormDraw.cpp $(F)
Dragon.o: ; g++ $(S) -g -c ./Objects/Dragon.cpp $(F)
DragonDraw.o: ; g++ $(S) -g -c ./ObjectsDraw/DragonDraw.cpp $(F)
HealToolDraw.o: ; g++ $(S) -g -c ./ObjectsDraw/HealToolDraw.cpp $(F)
PoisonToolDraw.o: ; g++ $(S) -g -c ./ObjectsDraw/PoisonToolDraw.cpp $(F)
SuperHealToolDraw.o: ; g++ $(S) -g -c ./ObjectsDraw/SuperHealToolDraw.cpp $(F)
clean: ; rm -rf *.o