cmake_minimum_required(VERSION 3.14)
add_executable(CM lex.yy.c tiny.tab.c util.c main.c analyze.c symtab.c)
configure_file(test.c test.c COPYONLY)