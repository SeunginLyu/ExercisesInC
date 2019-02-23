main.o: trout.h util.h main.c
	gcc -g -c -W trout.h util.h main.c

trout.o: trout.h trout.c
	gcc -g -c -W trout.h trout.c

util.o: util.h util.c
	gcc -g -c -W util.h util.c

trout: trout.o util.o main.o
	gcc -g -W -o trout trout.o util.o main.o