main: main.o unindent.o
	g++ -o main main.o unindent.o

unindent.o: unindent.cpp unindent.h
	g++ -c unindent.cpp

clean:
	rm -f main.o unindent.o