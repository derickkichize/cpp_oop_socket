CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11

all: main

main: main.cc NET/TCPSocket.cc NET/Socket.cc
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f main
