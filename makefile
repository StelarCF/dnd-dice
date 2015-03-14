all:
	clang++ dnd-dice.cpp --std=c++11 -o dnd-dice

install:
	cp dnd-dice /usr/bin/dnd
