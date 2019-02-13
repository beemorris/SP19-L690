all: pointer

pointer: pointer.cc
	g++ $< -o $@
	

# target: dependency
# $< = dependency
# $@ = target
frequency: frequency.cc
	g++ $< -o $@

hello: hello.cc
	g++ $< -o $@

unigram: unigram.cc
	g++ $< -o $@

score: score.o model.o
	g++ score.o model.o -o $@

score.o: score.cc 
	g++ -c -o $@ $< 

model.o: model.cc
	g++ -c -o $@ $< 
