output: NN.o math.o
	g++ NN.o -o output

NN.o: NN.cpp math.cpp
	g++ -c NN.cpp math.cpp

# took this out and using inlcude instead
# math.o: math.cpp math.h
# 	g++ -c math.cpp

clean:
	rm *.o

cleanall:
	rm *.o output
