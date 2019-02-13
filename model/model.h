// In the header file, you should:
//   1) Include relevant headers for other datatypes
//   2) Declare the function prototypes of the functions in your .cc file

#include <iostream> //  C++-style input/output
#include <stdio.h> // C-style input/output
#include <map> // make it so you can use dictionaries
#include <vector> // make it so you can use vectors (arrays/lists)

using namespace std;  // means we don't need to use std::map, std::string we can just use map/string.

// A class is a datastructure that contains both data and functions (in C++: methods) for
// operating on the data.
// The data is expressed by class members (variables)
// And methods are class methods
class Model {

private: // anything outside the class cannot access this

// here are our class-internal variables
map<string, double> model;

public: // everything outside the class can access this
// here are some methods
void print();
void load(char *filename);
double score(vector<string> sent);
string sentence_tostring(vector<string> sent);

}; 
