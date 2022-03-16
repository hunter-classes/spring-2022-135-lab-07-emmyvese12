main: main.o unindent.o indent.o
	g++ -o main main.o unindent.o indent.o

unindent.o: unindent.cpp unindent.h
	g++ -c unindent.cpp

indent.o: indent.cpp indent.h
	g++ -c indent.cpp
	
clean:
	rm -f main.o unindent.o indent.o