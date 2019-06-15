//
// Created by y on 2019-06-08.
//

#include <iostream>
#include "analyze.h"
#include "symtab.h"
#include "globals.h"

using namespace std;

/* pointer of the symtab */
static int location = 0;
static int skipOneEnter = FALSE;

static void nullProc(TreeNode *t)
{}

static void insertPost(TreeNode *t)
{
    if (t->nodekind == StmtK) {
        switch (t->kind.stmt) {
            case (CompK):
                exitScope(TRUE);

                break;
            default:
                break;
        }
    }
}

/**
 * Inserts identifiers
 * \ID
 * var-declaration -> type-specifier ID ; | type-specifier ID [ NUM ] ;<br>
 * fun-declaration -> type-specifier ID ( params ) compound-stmt<br>
 * param -> type-specifier ID | type-specifier ID [ ]<br>
 * var -> ID | ID [ expression ]<br>
 * call -> ID ( args )<br>
 * \Scope
 * compound-stmt -> { local-declarations statement-list }<br>
 * @param t AST
 */
static void insertPre(TreeNode *t)
{
    if (t->nodekind == StmtK) {
        switch (t->kind.stmt) {
            case (CompK):
                if (!skipOneEnter) // already entered scope in fun def
                    enterScope();
                skipOneEnter = FALSE;

                break;
            default:
                break;
        }
    } else if (t->nodekind == ExpK) {
        switch (t->kind.exp) {
            case (OpK):
                break;
            default:
                break;
        }
    } else if (t->nodekind == DeclK) {
        switch (t->kind.decl) {
            case (VarK): {
                /* ID after a type-specifier */
                string name = t->child[1]->attr.name;
                string type = t->child[0]->attr.type;
                int line = t->child[1]->lineno;
                if (lookup(name) == NOT_EXIST) {
#if VERBOSE
                    cout << "new " << type << " " << name << endl;
#endif
                    if (type == "int") {
                        insert(name, line, location++, 1);
                    } else if (type == "int*") {
                        int len = t->child[2]->attr.val;

                        insert(name, line, location, len);
                        location += len;
                    }


                } else if (lookup(name) == EXISTS_OUTER) {
#if VERBOSE
                    cout << "overwrite " << type << " " << name << endl;
#endif
                    if (type == "int") {
                        insert(name, line, location++, 1);
                    } else if (type == "int*") {
                        int len = t->child[2]->attr.val;

                        insert(name, line, location, len);
                        location += len;
                    }

                } else if (lookup(name) == EXISTS_THIS) {
#if VERBOSE
                    cout << "redefine " << name << endl;
#endif
                    cerr << "Error: redefine symbol" << endl;
                }


                break;
            }
            case (FuncK):
                /* parameter list */
                enterScope();
                skipOneEnter = TRUE;
                break;
            default:
                break;
        }
    }


}

static void checkNode(TreeNode *t)
{

}

static void insertTraverse( TreeNode *t)
{
    if (t != NULL) {
        insertPre(t);
        {
            int i;
            for (i = 0; i < MAXCHILDREN; i++)
                insertTraverse(t->child[i]);
        }
        insertPost(t);
        insertTraverse(t->sibling);
    }

}

Symtab buildSymtab(TreeNode *t)
{
#if VERBOSE
    cout << "\nBuild symtab start ..." << endl;
#endif
    insertTraverse(t);
//    printSymtab(listing);

    return program;
}

void typeCheck(TreeNode *t)
{
#if VERBOSE
    cout << "\nType check start ..." << endl;
#endif
//    traverse(t, nullProc, checkNode);

}
