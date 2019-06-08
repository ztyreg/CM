syntax: tiny.l tiny.y
	bison -d tiny.y; lex tiny.l;