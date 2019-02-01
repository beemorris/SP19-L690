// In the header file, you should:
//   1) Include relevant headers for other datatypes
//   2) Declare the function prototypes of the functions in your .cc file

#include <iostream> //  C++-style input/output
#include <stdio.h> // C-style input/output
#include <map> // make it so you can use dictionaries
#include <vector> // make it so you can use vectors (arrays/lists)

using namespace std;  // means we don't need to use std::map, std::string we can just use map/string.

// function prototypes
void model_print(map<string, double> model);
map<string, double> model_load(char *filename);
double model_score(map<string, double> model, vector<string> sent);
string model_sentence_tostring(vector<string> sent);

