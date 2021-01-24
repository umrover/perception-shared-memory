CC=g++
CFLAGS=-g -Wall

write: write
	$(CC) $(CFLAGS) -o write write.o

read: read
	$(CC) $(CFLAGS) -o read read.o

write.o: write.cpp shared_memory.cpp shared_memory.hpp
	$(CC) $(CFLAGS) -c write.cpp shared_memory.hpp shared_memory.cpp

read.o: read.cpp shared_memory.cpp shared_memory.hpp
	$(CC) $(CFLAGS) -c read.cpp shared_memory.hpp shared_memory.cpp

clean:
	rm *.out *.o
	rm -rf *.dSYM