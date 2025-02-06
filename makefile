# executable name
program: mergeSort.o
	g++ -std=c++11 mergeSort.o -o program

# make an object file
mergeSort.o: mergeSort.cpp
	g++ -std=c++11 -c mergeSort.cpp

# plot
plot: plot.py
	python3 plot.py

# clean
clean:
	rm *.o program
