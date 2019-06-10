//
// Created by y on 2019-06-08.
//

#include <iostream>
#include "symtab.h"

void printSymtab(FILE *listing)
{
    int level = 0;
//    fprintf(listing, "\nVar Name Loc Line Numbers Children\n");
//    fprintf(listing, "-------- --- ------------ --------\n");
    cout << "-----start-----" << endl;
    for ( Scope scopePtr = program;
          scopePtr != NULL;
          scopePtr = scopePtr->inner) {
        cout << "\nLevel " << level << endl;
        cout << "---------------" << endl;
        cout << "name loc lineno" << endl;
        for (const Symbol &item : scopePtr->symbols) {
            cout << item->name << " " << item->location;
            for (const int &range : item->lineno) {
                cout << " " << range;
            }
            cout << endl;
        }
        level++;
    }
    cout << "------end------" << endl;
}

lookupResult lookup(const string& name)
{
    for (const Symbol &item : currentScope->symbols) {
        if (item->name == name) {
            return EXISTS_THIS;
        }
    }

    Scope scopePtr;
    for ( scopePtr = currentScope->outer;
          scopePtr != NULL;
          scopePtr = scopePtr->outer) {
        for (const Symbol &item : scopePtr->symbols) {
            if (item->name == name) {
                return EXISTS_OUTER;
            }
        }
    }
    return NOT_EXIST;
}

void insert(const string& name, int line, int location, int length)
{
    Symbol symbolPtr;
    Scope scopePtr;
    if (location != -1) {
        /* new */
        Symbol symbol = (Symbol)malloc(sizeof(struct SymbolRec));
        symbol->name = name;
        symbol->lineno.push_back(line);
        symbol->location = location;
        symbol->length = length;
        currentScope->symbols.push_back(symbol);
#if VERBOSE
//        printSymtab(listing);
#endif

        return;
    }

    /* exists */
    for ( scopePtr = currentScope;
          scopePtr != NULL;
          scopePtr = scopePtr->outer) {
        for (const Symbol &item : scopePtr->symbols) {
            if (item->name == name) {
                item->lineno.push_back(line);
#if VERBOSE
//                printSymtab(listing);
#endif
                return;
            }
        }
    }


}

void enterScope()
{
#if VERBOSE
    cout << "enter scope" << endl;
#endif

    Scope innerScope = (Scope)malloc(sizeof(struct ScopeRec));

    currentScope->inner = innerScope;
    innerScope->outer = currentScope;
    currentScope = innerScope;

}

void exitScope(int setNULL)
{
#if VERBOSE
    cout << "exit scope" << endl;
#endif
    if (setNULL) {
        Scope holder = currentScope;
        currentScope = currentScope->outer;
        free(holder);
    } else {
        currentScope = currentScope->outer;
    }
}
/* printSymtab */