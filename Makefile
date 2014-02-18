main:
	g++ -Wall -g -std=c++11 main.cpp -lGL -lglfw -o main

demo:
	g++ -Wall -g -std=c++11 Maths.cpp Body.cpp World.cpp Demos.cpp -o demos
