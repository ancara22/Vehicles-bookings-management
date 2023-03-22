CXX = g++
CFLAGS = -g -std=c++17  -Wall -Wextra -Wpedantic


.PHONY : all
all: parking

parking: parking.cpp vehicles.o functions.o
	$(CXX) $(CFLAGS) -o $@ $^

functions.o: functions.cpp functions.h
	$(CXX) $(CFLAGS) -c functions.cpp


vehicles.o: vehicles.cpp vehicles.h
	$(CXX) $(CFLAGS) -c vehicles.cpp



.PHONY : test
test: parking_test.cpp functions.o  vehicles.o
	$(CXX) $(CFLAGS) -o $@ $^


.PHONY : clean
clean:
	rm -f *.gch
	rm -f  parking
	rm -f  *.o
	rm -f -rf *.dSYM
	rm -f *.out
	rm -f *#
	rm -f *.cpp~
	rm -f *.h~
	rm -f test
	rm -f newFile.dat


