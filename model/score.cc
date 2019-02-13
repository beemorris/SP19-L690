#include <iostream> //  C++-style input/output
#include <stdio.h> // C-style input/output
#include <map> // make it so you can use dictionaries
#include <vector> // make it so you can use vectors (arrays/lists)

#include "model.h" // include the header of the model file

using namespace std;  // means we don't need to use std::map, std::string we can just use map/string.

int
main(int argc, char **argv)
{
	FILE *in = stdin; // file handle to standard input
	char c = 0;  // this is the current input character we're reading
	string current_token = ""; // this is the current token we're working on
	vector<string> current_sentence; // this is the current sentence vector

	Model m; // our model is an instance of the 'Model' class

	m.load(argv[1]);

//	m.print();

	c = fgetc(in);

	while(!feof(in))
	{
		if(c == ' ') // new token
		{
			// add the token to the list of tokens in the sentence
			// use the 'push_back' function to add to the end of the list (like .append())
			current_sentence.push_back(current_token);
			current_token = "";
		} 
		else if(c == '\n') // end of a sentence
		{
			current_sentence.push_back(current_token);
			// score the current sentence
			double prob = m.score(current_sentence);
			// print out the probability and the sentence
			cout << prob << "\t" << m.sentence_tostring(current_sentence) << endl;
			current_sentence.clear(); // clear the sentence list
			current_token = "";
		}
		else
		{
			current_token += c;
		}
		c = fgetc(in);
	}

	return 0; // 0 is success, -1 is fail.

}
