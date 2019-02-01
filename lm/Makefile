TARGETS=unigram score
all: $(TARGETS)

# target: dependency
# $< = dependency
# $@ = target

unigram: unigram.cc
	g++ $< -o $@

# this is the final result that is executable
score: score.o model.o
	g++ score.o model.o -o $@

# .o files are not linked, they're just assembled/compiled
score.o: score.cc 
	g++ -c -o $@ $< 

model.o: model.cc
	g++ -c -o $@ $< 

clean:
	rm *.o $(TARGETS)
