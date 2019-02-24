endswith.o: endswith.h endswith.c
	gcc -g -c -W endswith.h endswith.c

test_endswith.o: endswith.h minunit.h test_endswith.c
	gcc -g -c -W endswith.h minunit.h test_endswith.c

test: endswith.o test_endswith.o
	gcc -g -W -o test endswith.o test_endswith.o