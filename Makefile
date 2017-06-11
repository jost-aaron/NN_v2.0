output: NN.o
	g++ NN.o -o output

NN.o: NN.cpp
	g++ -c NN.cpp

clean:
	rm *.o output
