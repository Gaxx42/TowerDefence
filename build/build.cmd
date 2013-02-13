set output=../bin/towerdefence.exe
set engine=../engine/timer.cpp ../engine/game.cpp ../engine/imagehandler.cpp
set engine=%engine% ../engine/main.cpp ../engine/container.cpp
set engine=%engine% ../engine/state_machine.cpp
set entities=../entities/enemy.cpp ../entities/tower.cpp ../entities/particle.cpp
set flags= -lmingw32 -lSDLmain -lSDL -Wall -DDEBUG
set includes=-I../includes

g++ -o %output% %engine% %entities% %flags% %includes%
