
output: main.o bulldozer.o humanic.o prime.o robocop.o robot.o roomba.o
	g++ -std=c++11 main.o bulldozer.o humanic.o prime.o robocop.o robot.o roomba.o -o output
	
main.o: main.cpp
	g++ -c -std=c++11 main.cpp

bulldozer.o:bulldozer.cpp bulldozer.h
	g++ -c -std=c++11 bulldozer.cpp
	
humanic.o:humanic.cpp humanic.h
	g++ -c -std=c++11 humanic.cpp
	
prime.o:prime.cpp prime.h
	g++ -c -std=c++11 prime.cpp
	
robocop.o:robocop.cpp robocop.h
	g++ -c -std=c++11 robocop.cpp
	
robot.o:robot.cpp robot.h
	g++ -c -std=c++11 robot.cpp

roomba.o:roomba.cpp roomba.h
	g++ -c -std=c++11 roomba.cpp
						
clean:
	rm *.o output
