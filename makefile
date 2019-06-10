all: syntax analyze.cpp lex.yy.cpp main.cpp symtab.cpp tiny.tab.cpp util.cpp analyze.h symtab.h tiny.tab.h util.h parse.h scan.h
	g++ analyze.cpp lex.yy.cpp main.cpp symtab.cpp tiny.tab.cpp util.cpp

syntax: tiny.l tiny.y
	bison -d tiny.y; lex tiny.l; mv lex.yy.c lex.yy.cpp; mv tiny.tab.c tiny.tab.cpp

test: all
	./a.out
