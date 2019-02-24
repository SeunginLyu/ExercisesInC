endswith.o: endswith.h endswith.c
	gcc -g -c -W endswith.h endswith.c

test_endswith.o: endswith.h minunit.h test_endswith.c
	gcc -g -c -W endswith.h minunit.h test_endswith.c

util.o: util.h util.c
	gcc -g -c util.h util.c

test_util.o: util.h util.c test_util.c
	gcc -g -c util.h util.c test_util.c
	
test_util: util.o test_util.o
	gcc -g -o test_util.out util.o test_util.o