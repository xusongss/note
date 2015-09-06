all:
	g++ -c c++_lib.cpp -o c++_lib.a	
	gcc main.c  c++_lib.a -lstdc++ -o test	
clean:
	-rm c++_lib.a
	-rm test
