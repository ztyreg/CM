all: globals.h parse.h scan.h util.c util.h
	bison -d tiny.y; lex tiny.l; gcc -w tiny.tab.c lex.yy.c util.c

run: all
	./a.out