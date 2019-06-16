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
Scope *program = new Scope();
Scope *sp = program;

static void nullProc(TreeNode *t)
{}

static void postProc(TreeNode *t)
{
    if (t->nodekind == StmtK) {
        switch (t->kind.stmt) {
            case (CompK):
                sp = exitScope(sp);

                break;
            default:
                break;
        }
    } else if (t->nodekind == ExpK) {

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
static void preProc(TreeNode *t)
{
    if (t->nodekind == StmtK) {
        switch (t->kind.stmt) {
            case (CompK):
                if (!skipOneEnter) // already entered scope in fun def
                    sp = enterScope(sp);
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
                if (lookup(name, sp) == NOT_EXIST) {
                    cout << "new " << type << " " << name << endl;
                    if (type == "int") {
                        sp = insert(name, line, location++, 1, sp);
                    } else if (type == "int*") {
                        int len = t->child[2]->attr.val;

                        sp = insert(name, line, location, len, sp);
                        location += len;
                    }


                } else if (lookup(name, sp) == EXISTS_OUTER) {
                    cout << "overwrite " << type << " " << name << endl;
                    if (type == "int") {
                        sp = insert(name, line, location++, 1, sp);
                    } else if (type == "int*") {
                        int len = t->child[2]->attr.val;

                        sp = insert(name, line, location, len, sp);
                        location += len;
                    }

                } else if (lookup(name, sp) == EXISTS_THIS) {
                    cout << "redefine " << name << endl;
                    cerr << "Error: redefine symbol" << endl;
                }


                break;
            }
            case (FuncK):
                sp = enterScope(sp);
                skipOneEnter = TRUE;


                /* parameter list as local variable */



                break;
            default:
                break;
        }
    }


}

static void traverse(TreeNode *t)
{
    if (t != NULL) {
        preProc(t);
        {
            int i;
            for (i = 0; i < MAXCHILDREN; i++)
                traverse(t->child[i]);
        }
        postProc(t);
        traverse(t->sibling);
    }

}

Scope *buildSymtab(TreeNode *t)
{
    cout << "\nBuild symtab start ..." << endl;
    traverse(t);
    return program;

}

