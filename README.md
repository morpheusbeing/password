In another life at another time, I used to have to give out passwords to students, who would forget them!

So, I wrote a simple pronouncable password generator in tcl/tk.

As I am revising my c++ knowledge, I have taken the concept, and using the boost libraries,
have recreated my creation in a compiled version for Gnu/Linux. No doubt it could be modded for 
Mac and Windows, but someone else can do that if the need arises.

The compile instructions are in the source code, but it is simple:
* you must have boost dev libraries installed.
* you must have g++ installed.
* then, g++ -Wall -o password password.cpp -lboost_random.

It will create:
* pronouncable passwords from 1 to a number specified on the command line.
* long passwords from 1 to number specified of a specified length (20 characters is the default).

I learnt a lot about processing commandline arguments in c++.

I welcome comments and feedback, and I hope you find it useful.
