battle: main.o creature.o barbarian.o harryPotter.o medusa.o blueMen.o babaYaga.o creatureQ.o loserStack.o
	g++ main.o creature.o barbarian.o harryPotter.o medusa.o blueMen.o babaYaga.o creatureQ.o loserStack.o -o battle

main.o: main.cpp
	g++ -c main.cpp

creature.o: creature.cpp creature.hpp
	g++ -c creature.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -c barbarian.cpp

harryPotter.o: harryPotter.cpp harryPotter.hpp
	g++ -c harryPotter.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -c medusa.cpp

blueMen.o: blueMen.cpp blueMen.hpp
	g++ -c blueMen.cpp

babaYaga.o: babaYaga.cpp babaYaga.hpp
	g++ -c babaYaga.cpp

creatureQ.o: creatureQ.cpp creatureQ.hpp
	g++ -c creatureQ.cpp

loserStack.o: loserStack.cpp loserStack.hpp
	g++ -c loserStack.cpp

clean:
	rm *.o battle




