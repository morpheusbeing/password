History
=======
In another life at another time, I used to have to give out passwords to students, who would forget them! 
I remember giving a new password to the same student 3 times in the one day.

So, I wrote a simple gui pronouncable password generator in tcl/tk, where I could generate say 10, and let the student pick one.

As I am revising my c++ knowledge, I have taken the concept, and using the boost libraries,
have recreated my creation in a cli compiled version for Gnu/Linux. No doubt it could be modded for 
Mac and Windows, but someone else can do that if the need arises.

The compile instructions are in the source code, but it is simple:
* you must have boost dev libraries installed.
* you must have g++ installed.
* then, g++ -Wall -o password password.cpp -lboost_random.

It will create:
* pronouncable passwords of an internal pattern from 1 to a number specified on the command line.
* long passwords from 1 to number specified of a specified length (20 characters is the default). These are really good for computer
systems that need secure passwords that are not accessed very often.

I learnt a lot about processing commandline arguments in c++.

I welcome comments and feedback, and I hope you find it useful.

Contributing
============

We love community code, bug fixes, and other forms of contribution. We use GitHub Issues and Pull Requests for contributions to this and all other code. To get started:

* Fork this repository.
* Clone your fork or add the remote if you already have a clone of the repository.
* Create a topic branch for your change.
* Make your change and commit. Use a clear and descriptive commit message, spanning multiple lines if detailed explanation is needed.
* Push to your fork of the repository and then send a pull request.
* I will review your patch and merge it into the main repository or send you feedback.

