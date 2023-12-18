target = UnitTest
maintarget = main
servertarget = server
sources = UnitTest.cpp mdfile.cpp mdfile.h
mainsrc = main.cpp mdfile.cpp mdfile.h
server = server.cpp mdfile.cpp mdfile.h
CC = g++
CCFlags = -Wall
LDLIBS = -lcrypto++
OPT = -Ofast
all:build main server
build:
	$(CC) $(CCFlags) $(OPT) $(sources) -o $(target) $(LDLIBS)
main:
	$(CC) $(CCFlags) $(OPT) $(mainsrc) -o $(maintarget) $(LDLIBS)
server:
	$(CC) $(CCFlags) $(OPT) $(server) -o $(servertarget) $(LDLIBS)
dbg:
	$(CC) -g $(sources) -o $(target)DBG
