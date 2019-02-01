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
	map<string, double> model; // language model, token (string) -> probability (double)
	char c = 0;  // this is the current input character we're reading
	string current_token = ""; // this is the current token we're working on
	vector<string> current_sentence; // this is the current sentence vector

//	cout << argv[0] << " " << argv[1] << " " << argc << endl;

	model = model_load(argv[1]);

//	model_print(model);

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
			double prob = model_score(model, current_sentence);
			// print out the probability and the sentence
			cout << prob << "\t" << model_sentence_tostring(current_sentence) << endl;
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
