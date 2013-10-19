// password.cpp
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// compile as
// g++ -o password password.cpp -lboost_random

#include <iostream>
#include <string>
#include <vector>

#include <boost/random/random_device.hpp>
#include <boost/nondet_random.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/uniform_int_distribution.hpp>

void password_pronounce(int number)
{
    // We first define the characters that we're going
    //     to allow.  This is pretty much just the characters
    //     on a standard keyboard.
	std::string chars("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ");
	std::string vowels("aeiouAEIOU");
	std::string numbers("1234567890");
	std::string symbols("!@#$%^&*()`~-_=+[{]}\\|;:'\",<.>/? ");
    // We use __random_device as a source of entropy, since we want
    //     passwords that are not predictable.
    
    boost::random::random_device rng;
    // Now develop uniform distribution
    boost::random::uniform_int_distribution<> chars_dist(0, chars.size() - 1);
    boost::random::uniform_int_distribution<> vowels_dist(0, vowels.size() - 1);
    boost::random::uniform_int_distribution<> symbols_dist(0, symbols.size() - 1);
    boost::random::uniform_int_distribution<> numbers_dist(0, numbers.size() - 1);
    
    for (int i = 0; i < number; ++i) 
    {
	    // Display group of char/vowel/char to get pronouncable password
    	for (int j = 0; j < 3; ++j) 
    	{
			std::cout << chars[chars_dist(rng)];
			std::cout << vowels[vowels_dist(rng)];
			std::cout << chars[chars_dist(rng)];
		}
    	// now add a symbol
		std::cout << symbols[symbols_dist(rng)];
		// now add 3 numbers to end
		for (int i = 0; i < 3; ++i) 
		{
			std::cout << numbers[numbers_dist(rng)];
		}
    	std::cout << std::endl;
    }
}

void password_long(int& num, int len = 20)
{
   std::string chars(
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "1234567890"
        "!@#$%^&*()"
        "`~-_=+[{]}\\|;:'\",<.>/?");
   
    boost::random_device rng;
    boost::variate_generator<boost::random_device&, boost::random::uniform_int_distribution<> >
        gen(rng, boost::random::uniform_int_distribution<>(0, chars.size()));
    
    // the number asked for
    for (int i = 0; i < num; ++i) 
    {
	    // of the length requested - if none, use standard length of 20
    	for (int j = 0; j < len; ++j) 
    	{
    		std::cout << chars[gen()];
    	}
		std::cout << std::endl;
    }
}

static void show_usage(std::string name) {
			std::cerr << "usage: " << name << "  [options] " << std::endl;
			std::cerr << " l - create [n] long password of [n] (20 is default) characters for system useage." << std::endl;
			std::cerr << " p - create [n] pronouncable passwords as cvccvccvcsnnn " << std::endl;
			std::cerr << "                where c = constanant " << std::endl;
			std::cerr << "                      v = vowel" << std::endl;
			std::cerr << "                      s = symbol" << std::endl;
			std::cerr << "                      n = digit" << std::endl;
}

int main(int argc, char *argv[]) 
{
   int length = 20;
   int number = 1;
   
   if (argc < 2) {
      show_usage(argv[0]);
      return 1;
   }

   std::vector <std::string> commandline;

   for (int i = 1; i < argc; ++i) 
   {
	   std::string arg = argv[i];
	   
	   if ((arg == "-h" ) || (arg == "--help") || (arg == "-?")) 
	   {
    	  show_usage(argv[0]);
	   } 
	   else if ((arg == "-l") || (arg == "--long")) 
	   {
		   // we want a set number of long passwords
		   if (i + 1 < argc) 
		   {
			   std::string myString = argv[++i];
		   	   number = atoi(myString.c_str());
		   }
		   // if yet another argument, we want them to be of set length
		   if (i + 1 < argc) 
		   {
			   std::string myString = argv[++i];
			   length = atoi(myString.c_str());
			   password_long(number, length);
		   }
		   else
		       password_long(number);

	   }
	   else if ((arg == "-p") || (arg == "--pronounce")) 
	   {
		   if (i + 1 < argc) 
		   { 
			   std::string myString = argv[++i];
			   number = atoi(myString.c_str());
		   }
		   password_pronounce(number);
	   }
	   else
	   {
		   std::cerr << "Houston, we have a problem." << std::endl;
		   std::cerr << "Why don't you try again with -h option. " << std::endl;
	   }
    }
	return 0;
}

//   EOF

