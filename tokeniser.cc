#include <iostream>

// C standard input header file... a header file is some file that gives
// you a set of functions or variables that you can call
#include <stdio.h> // fgetc() comes from here

using namespace std;

// Tokeniser, separate input on space, and number tokens.

int main(int argc, char **argv)  // in older programs you might see: *argv[]
// argc = count of the command line arguments
// argv = C array of the command line arguments
// If you run the program like:
// ./tokeniser a b c 
// argc = 4
// argv = ['./tokeniser', 'a', 'b', 'c']
{
	int token_count = 1;
	string current_token = "";
	char c = 0;
	// * means pointer, don't worry about that yet
	// FILE is the type of the variable, it's a Unix FILE "handle"
	//   handle means a way of referencing an open file on Unix.
	// 'in' is the variable name
	// stdin is the open file handle for standard input, the way
	//   to address input from the '<' symbol or the '|' symbol on 
	//   the command line
	FILE *in = stdin;

	// Add the current character we've read to the current token.
	c = fgetc(in);
	// Read through input character by character until end of file
	while(!feof(in)) 
	{
		//cerr << "token_count= " << token_count << " || c= " << c << " || current_token= " << current_token << endl;
		current_token += c;
		if(c == ' ')
		{
			cout << token_count << "\t" << current_token << endl;
			current_token = "";
			token_count += 1;
		}	
		if(c == '\n') 
		{
			cout << token_count << "\t" << current_token << endl;
			current_token = "";
			token_count = 1;
		}
		c = fgetc(in);	
	}
}
