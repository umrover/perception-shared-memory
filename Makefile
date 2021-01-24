CC=g++
CFLAGS=-g -Wall

write: write.o
	$(CC) $(CFLAGS) -o write write.o

read: read.o
	$(CC) $(CFLAGS) -o read read.o

write.o: shared_memory.hpp
	$(CC) $(CFLAGS) -c write.cpp shared_memory.hpp

read.o: shared_memory.hpp
	$(CC) $(CFLAGS) -c read.cpp shared_memory.hpp

clean:
	rm *.o *.gch
	rm -rf a.out.dSYM