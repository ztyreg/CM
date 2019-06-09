//
// Created by y on 2019-06-08.
//

#ifndef CM_SYMTAB_H
#define CM_SYMTAB_H

#include <vector>
#include <string>

using namespace std;

/* SIZE is the size of the hash table */
#define SIZE 211

/*
 * Tree-based implementation
 * Linked list in each scope
 */

typedef struct SymtabRec {
    explicit SymtabRec(const string& name) :
    name(name), loc(-1), outer(nullptr), inner(nullptr) {}

    string name;
    int loc; //memory location
    vector<int> lineno; //occurrences
    vector<struct SymtabRec *> symbols; //linked list
    struct SymtabRec * outer; //outer scope
    struct SymtabRec * inner; //if symbol is associated with an inner scope

} *Symtab;

static Symtab program = new SymtabRec((string &) "0"); //0 represents main

//void hash();

void insert(string name);

void lookup(string name);

void enterScope();

void exitScope();

void printSymtab(FILE *listing);

#endif //CM_SYMTAB_H
