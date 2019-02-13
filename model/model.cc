// using <> means that it searches in the global include paths for the header file
// using "" means that it searches in the current directory for the header file


//#include <model.h> // include all of the headers from the header file (function prototypes + includes)
#include "model.h"

// void is a special datatype for undefined/unused types
void
Model::print()
{
	map<string, double>::iterator it; // define iterator over the model map

	for(it = model.begin(); it != model.end(); it++)
	{
		cout << it->second << " " << it->first << endl;
	}
	
	return;
}

void
Model::load(char *filename)      // function name and arguments
{
	FILE *f_model = 0; // file handle to the model file
	char c = 0; // the current input character
	string cell = ""; // the current cell we are in in the file

	// open the model file for reading
	f_model = fopen(filename, "r"); // r = reading

// col1		col2
//row1 0.0333333	This
//row2 0.133333	a
//row3 0.0333333	after
	
	c = fgetc(f_model); // get the next character from the model file

	// tab = column separator
	// newline = row separator
	double last_prob = 0.0; // this is the last probability that we've seen
	while(!feof(f_model)) 
	{
		if(c == '\t') // we are in column 2
		{
			// string = C++ datatype, char* = C datatype
			last_prob = strtod(cell.c_str(), NULL); // convert string to double
			cell = "";
		}
		else if(c == '\n') // we are in column 1
		{
			model[cell] = last_prob; // add the pair to the model map
			cell = "";
		}
		else
		{
			cell += c; // add the current character to the current cell
		}

		c = fgetc(f_model); // get the next character from the model file
	}
	
	fclose(f_model);
}

double
Model::score(vector<string> sent)
{
	double prob = 1.0;
	// model = {'dog': 0.4, 'cat': 0.2, ...}
	// sent = ['This', 'is', 'a', 'dog']

	vector<string>::iterator it; // make an iterator for the sentence

	for(it = sent.begin(); it != sent.end(); it++)
	{
		// TODO: deal with unknown words
	
		if(model.find(*it) != model.end()) // if we find the token in the model
		{
			prob = prob * model[*it]; // multiply the current probability by the probability of the token
		}	
	}
	

	return prob;
}

string
Model::sentence_tostring(vector<string> sent)
{
	vector<string>::iterator it;
	string sentence = "";

	for(it = sent.begin(); it != sent.end(); it++)
	{
		sentence = sentence + *it + " ";
	}	

	return sentence;
}


