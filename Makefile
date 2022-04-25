main: main.o unindent.o indent.o
	g++ -o main main.o unindent.o indent.o

tests: tests.o unindent.o indent.o
	g++ -o tests tests.o unindent.o indent.o

main.o: main.cpp unindent.h indent.h
	g++ -c main.cpp

unindent.o: unindent.cpp unindent.h
	g++ -c unindent.cpp

indent.o: indent.cpp indent.h
	g++ -c indent.cpp

tests.o: tests.cpp doctest.h unindent.h indent.h
	g++ -c tests.cpp
	
clean:
	rm -f main tests main.o unindent.o indent.o tests.o