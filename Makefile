
cmd = -s -O3 -std=c++17 -mwindows
cmdsfml = -lsfml-window -lsfml-system -lsfml-graphics
libs = -LC:\DEV_TOOLS\SFML-2.5.0\lib
includes = -IC:\DEV_TOOLS\SFML-2.5.0\include
all: link compile

compile:
	g++ main.o -o CowSayDraw $(cmdsfml) $(cmd) $(includes) $(libs)
link:
	g++ -c main.cpp $(cmd) $(includes) $(libs)