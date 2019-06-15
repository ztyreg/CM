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

static Scope currentScope = program;

typedef enum {EXISTS_OUTER, EXISTS_THIS, NOT_EXIST} lookupResult;


//void hash();

void insert(const string& name, int line, int location, int length);

lookupResult lookup(const string& name);

void enterScope();

void exitScope();

void printSymtab(Scope scopePtr);

void printProgram();

#endif //CM_SYMTAB_H
