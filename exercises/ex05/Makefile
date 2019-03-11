rand.o: rand.h rand.c
	gcc -g -c -W rand.c

test1.o: test1.c
	gcc -g -c -W test1.c
	
test_rand: rand.o test1.o
	gcc -g -o test_rand.out rand.o test1.o

test2.o: test2.c
	gcc -g -c -W test2.c
	
test_rand2: rand.o test2.o
	gcc -g -o test_rand2.out rand.o test2.o

test3.o: test3.c
	gcc -g -c -W test3.c
	
test_rand3: rand.o test3.o
	gcc -g -o test_rand3.out rand.o test3.o

time_rand.o: rand.h time_rand.c
	gcc -g -c time_rand.c

time_rand: rand.o time_rand.o
	gcc -g -o time_rand.out rand.o time_rand.o

shapes.o: shapes.h shapes.c
	gcc -g -c -W shapes.c

lines.o: shapes.h lines.c
	gcc -g -c -W lines.c

test_lines: shapes.o lines.o
	gcc -g -o lines.out lines.o shapes.o