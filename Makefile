target = UnitTest
maintarget = main
sources = UnitTest.cpp mdfile.cpp mdfile.h
mainsrc = main.cpp mdfile.cpp mdfile.h
CC = g++
CCFlags = -Wall
LDLIBS = -lcrypto++
OPT = -Ofast
all:build main
build:
	$(CC) $(CCFlags) $(OPT) $(sources) -o $(target) $(LDLIBS)
main:
	$(CC) $(CCFlags) $(OPT) $(mainsrc) -o $(maintarget) $(LDLIBS)
dbg:
	$(CC) -g $(sources) -o $(target)DBG
