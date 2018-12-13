CC = g++
exe_file = real_estate
$(exe_file): property.o house.o apartment.o business.o game.o driver.o
	$(CC) property.o house.o apartment.o business.o game.o driver.o -o $(exe_file)
properties.o: property.cpp
	$(CC) -c property.cpp
house.o: house.cpp
	$(CC) -c house.cpp
apartment.o: apartment.cpp
	$(CC) -c apartment.cpp
business.o: business.cpp
	$(CC) -c business.cpp
game.o: game.cpp
	$(CC) -c game.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
