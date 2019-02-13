#include <stdio.h>
#include <iostream>

using namespace std;

// struct in C
// a struct (short for structure) is a datatype that allows you to embed
// other datatypes inside.
// kind of like a class, only no functions/methods
typedef struct record {
	int id;
	char *buffer;
} record;

int 
main(int argc, char **argv)
{
	char c = 'a'; // a single character
	char *s_buffer = "123456789"; // a "c-style" string.
	// pointer to an area of memory that we set to "123456789"
	// the area of memory is allocated on the stack
	// the "123456789" is a "string".
	// in C, strings are terminated by NULL, literally '\0'
	char a_buffer[10] = "123456789";
	// this is an array of characters
	// arrays in C are specified with square brackets foo[] 
	// an array in C _must_ be fixed size

	// python: a_buffer = ['1','2','3','4','5','6','7','8','9']

	printf("%c / %s / %s\n", c, s_buffer, a_buffer);
	printf("%c / %c / %c\n", c, s_buffer[4], a_buffer[4]);
	printf("%c / %c", s_buffer[10], a_buffer[10]);
	printf("%c / %c", s_buffer[12], a_buffer[12]);
	printf("\n");

	char *ptr = s_buffer; // this is a character pointer to the 
				//first memory address of the string 's_buffer'
	int i = 0;	
	for(i = 0; i < 10; i++)
	{
		// print out both:
		// *ptr = the value of the area of memory
		// ptr = the address of the area of memory
		printf("%d: %c / %d / %x\n", i, *ptr, *ptr, ptr);
		ptr++; // increment the pointer by 1, meaning it points to the next address
	}

	printf("a_buffer = %s\n", a_buffer);

	// arrays can be changed by indexing, strings cannot!
	a_buffer[5] = '1';
	// s_buffer[5] = '1' --> segmentation fault
	
	printf("a_buffer' = %s\n", a_buffer);

	// %c = character
	// %s = string
	// %d = integer
	// %.2f = float/double with 2 points of precision

	// define a pointer to our struct datatype
	record *r;
	// we allocate enough memory to store it ... this memory is on the heap (not the stack)
	// (record *) = cast = convert one type to another "cast one type to another"
	// -- does not work between all types!
	// malloc() returns (void *) type by default
	// sizeof() = gives the size of a particular datatype
	r = (record *)malloc(sizeof(record));
	r->id = 200; // int
	r->buffer = "abcdefghi"; // char*
	
	printf("%d (sizeof: %d, %x) - %s (sizeof: %d, %x)\n", r->id, sizeof(r->id), (*r).id, r->buffer, sizeof(r->buffer), (*r).buffer);

	free(r); // frees the memory that we have previously allocated
	// when you have malloc() you should also have a free()
	
	
	return 0;
}
