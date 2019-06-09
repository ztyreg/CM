syntax: tiny.l tiny.y
	bison -d tiny.y; lex tiny.l; mv lex.yy.c lex.yy.cpp; mv tiny.tab.c tiny.tab.cpp