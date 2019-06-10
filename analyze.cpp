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
                if (type == "int") {
                    if (lookup(name) == NOT_EXIST) {
#if VERBOSE
                        cout << "new int " << name << endl;
#endif
                        insert(name, line, location++, 1);


                    } else if (lookup(name) == EXISTS_OUTER) {
#if VERBOSE
                        cout << "overwrite int " << name << endl;
#endif
                        insert(name, line, location++, 1);

                    } else if (lookup(name) == EXISTS_THIS) {
#if VERBOSE
                        cout << "redefine int " << name << endl;
#endif
                        cout << "Error: redefine symbol";

                    }
                } else if (type == "int*") {
#if VERBOSE
                    cout << "int* " << name << endl;
#endif
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

static void traverse(
        TreeNode *t,
        void (*preProc)(TreeNode *),
        void (*postProc)(TreeNode *))
{
    if (t != nullptr) {
        preProc(t);
        {
            int i;
            for (i = 0; i < MAXCHILDREN; i++)
                traverse(t->child[i], preProc, postProc);
        }
        postProc(t);
        traverse(t->sibling, preProc, postProc);
    }

}

void buildSymtab(TreeNode *t)
{
#if VERBOSE
    cout << "\nBuild symtab start ..." << endl;
#endif
    traverse(t, insertPre, insertPost);
    printSymtab(listing);

}

void typeCheck(TreeNode *t)
{
#if VERBOSE
    cout << "\nType check start ..." << endl;
#endif
    traverse(t, nullProc, checkNode);

}
