# makefile for password

all: password.cpp
	g++ -o password password.cpp -lboost_random

clean:
	$(RM) password

