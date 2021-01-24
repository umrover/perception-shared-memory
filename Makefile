CC=g++
CFLAGS=-g -Wall

write_memory: write.cpp shared_memory.cpp shared_memory.h
	$(CC) -o write.out $(CFLAGS) write.cpp shared_memory.cpp

read_memory: read.cpp shared_memory.cpp shared_memory.h
	$(CC) -o read.out $(CFLAGS) read.cpp shared_memory.cpp

clean:
	rm *.out
	rm -rf *.dSYM