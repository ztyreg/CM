//
// Created by y on 2019-06-08.
//

#include <iostream>
#include "symtab.h"

// for printSymtab
int level = 0;

void printSymtab(Scope *scopePtr)
{
    if (scopePtr == NULL) return;

    cout << "\nLevel " << level << endl;
    cout << "---------------" << endl;

    for (Symbol *item : scopePtr->symbols) {
        cout << item->type << " "
             << item->name << " " 
             << item->location;
        for (const int &range : item->lineno) {
            cout << " " << range;
        }
        cout << endl;
    }

    level++;
    for (Scope *item : scopePtr->inner) {
        printSymtab(item);
    }
    level--;

    cout << "------end------" << endl;
}

lookupResult lookup(const string &name, const string &type, Scope *currentScope)
{
    for (Symbol *item : currentScope->symbols) {
        if (item->name == name && item->type == type) {
            return EXISTS_THIS;
        }
    }

    Scope *scopePtr;
    for (scopePtr = currentScope->outer;
         scopePtr != NULL;
         scopePtr = scopePtr->outer) {
        for (Symbol *item : scopePtr->symbols) {
            if (item->name == name && item->type == type) {
                return EXISTS_OUTER;
            }
        }
    }
    return NOT_EXIST;
}

int findLoc(const string &name, const string &type, Scope *currentScope)
{
    cout << "looking up " << name << endl;

    Scope *scopePtr;
    for (scopePtr = currentScope;
         scopePtr != NULL;
         scopePtr = scopePtr->outer) {
        for (Symbol *item : scopePtr->symbols) {
            if (item->name == name && item->type == type) {
                return item->location;
            }
        }
    }
    cerr << "Not found" << endl;
    return -1;
}

Scope *insert(const string &name, const string &type, int line, int location, int length, Scope *sp)
{
    if (location != -1) {
        /* new */
        Symbol *symbol = new Symbol();
        symbol->name = name;
        symbol->type = type;
        symbol->lineno.push_back(line);
        symbol->location = location;
        symbol->length = length;
        sp->symbols.push_back(symbol);

        return sp;
    }

    /* exists */
    Scope *scopePtr;
    for (scopePtr = sp;
         scopePtr != NULL;
         scopePtr = scopePtr->outer) {
        for (Symbol *item : scopePtr->symbols) {
            if (item->name == name && item->type == type) {
                item->lineno.push_back(line);
                return sp;
            }
        }
    }


    return sp;
}

Scope *enterScope(Scope *sp)
{
    cout << "enter scope" << endl;

    Scope *innerScope = new Scope();

    sp->inner.push_back(innerScope);
    innerScope->outer = sp;
    sp = innerScope;
    return sp;
}

Scope *enterFirstScope(Scope *sp)
{
    cout << "enter scope" << endl;

    return sp->inner[0];
}

Scope *exitScope(Scope *sp)
{
    cout << "exit scope" << endl;
    sp = sp->outer;
    return sp;
}

Scope *exitScopeSetNull(Scope *sp)
{
    cout << "exit scope" << endl;
    sp = sp->outer;
    Scope *temp = sp->inner[0];
    sp->inner.erase(sp->inner.begin());
    delete temp;

    return sp;
}
/* printSymtab */