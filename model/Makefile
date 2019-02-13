all: score

# The binary (executable) target "score" depends on the two object files
score: score.o model.o
	g++ -o $@ score.o model.o

# split the compilation of source files to avoid having to recompile
# the same thing multiple times if it is not changed

# .o files are "object" code. 
# this is compiled code, that is not executable
%.o: %.cc
	g++ -c -o $@ $<

clean:
	rm *.o score
