logey: logey.cpp
	g++ -std=c++11 $^ -o $@

clean:
	rm -f *.o logey
