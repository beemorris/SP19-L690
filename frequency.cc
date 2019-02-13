#include <iostream>
#include <stdio.h>
#include <map> // The 'map' class, which is like Python's "dict()" // keyed array from X->Y

// If you don't have this, then you need to prepend all STL std calls with std::
using namespace std;

// Program to count frequency of tokens in the input.

int main(int argc, char **argv)
{
	int counter = 0;
	char c = 0; // current input character 
	string current_token = ""; // current token we're reading
	FILE *in = stdin; // input file
	map<string, int> lookup; // lookup table from token -> frequency; variable name = lookup
	// Variables are always TYPE SPACE NAME 

	c = fgetc(in); // This reads the first character in the input

	// PRO TIP: Use 'man <function name> on the command line to find out 
	// about specific functions, e.g.
	// $ man feof
	while(!feof(in))  // feof = file end of file. 
	{
		current_token += c;
		if(c == ' ') 
		{
			// Either add to map if the key is not in the map, or
			// increment the counter in the map by 1
			
			// Is the current token in the map?
			map<string,int>::iterator it;
			it = lookup.find(current_token);
			if(it == lookup.end())  // If we haven't found anything, e.g. the iterator returns nothing
			{
				// Add the key to the dictionary and initialise it to 0
				lookup[current_token] = 0;
			}

			// These two are equivalent:
//			lookup[current_token] += 1;
			lookup[current_token]++; 

			// Set the current token to empty
			current_token = "";
		}

		c = fgetc(in); // This reads all subsequent characters until end of file
	}

	map<string,int>::iterator it;
	// Read through the lookup table (dictionary) key by key
	// lookup.begin() = first element in the dictionary (map)
	// lookup.end() = last element in the dictionary (map)
	// it++ = increment by 1
	for(it = lookup.begin(); it != lookup.end(); it++)
	{
		// it->second = the value
		// it->first = the key
		// "\t" = tab
		cout << " " << it->second << "\t" << it->first << endl;
	}

	return 0;
}
