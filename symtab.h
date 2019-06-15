//
// Created by y on 2019-06-08.
//

#ifndef CM_SYMTAB_H
#define CM_SYMTAB_H

#include <vector>
#include <string>
#include "globals.h"

using namespace std;

/* SIZE is the size of the hash table */
#define SIZE 211

/*
 * Tree-based implementation
 * Linked list in each scope
 */

typedef struct SymbolRec {
    string name;
    int location; //memory location
    int length;
    vector<int> lineno; //occurrences

} * Symbol;

typedef struct ScopeRec {
    ScopeRec() : outer(NULL), inner(NULL) {}

    vector<Symbol> symbols;
    struct ScopeRec * outer; //outer scope
    struct ScopeRec * inner; //if symbol is associated with an inner scope

} *Scope;

typedef Scope Symtab;

//0 represents the program
static Symtab program = (Scope)malloc(sizeof(struct ScopeRec));
static Scope currentScope = program;

typedef enum {EXISTS_OUTER, EXISTS_THIS, NOT_EXIST} lookupResult;


//void hash();

void insert(const string& name, int line, int location, int length);

lookupResult lookup(const string& name);

void enterScope();

void exitScope(int setNull);

void printSymtab(FILE *listing);

void printProgram();

#endif //CM_SYMTAB_H
