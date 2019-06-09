cmake_minimum_required(VERSION 3.14)
add_executable(CM lex.yy.cpp tiny.tab.cpp util.cpp main.cpp analyze.cpp symtab.cpp)
configure_file(test.c test.c COPYONLY)