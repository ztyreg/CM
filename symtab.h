//
// Created by y on 2019-06-08.
//

#ifndef CM_SYMTAB_H
#define CM_SYMTAB_H

/*
 * Hash table implementation
 */

typedef struct LinenoRec {
    int lineno;
    struct LinenoRec *next;

} *Lineno;

typedef struct SymtabRec {
    char name[31]; //max name length: 31
    int loc; //memory location
    Lineno linenoList;
    struct SymtabRec *next;

} *Symtab;

void hash();

void insert();

void lookup();

void create();

#endif //CM_SYMTAB_H
