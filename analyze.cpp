//
// Created by y on 2019-06-08.
//

#include "analyze.h"
#include "symtab.h"
#include "globals.h"

/* pointer of the symtab */
static Symtab ptr = program;

static void nullProc(TreeNode *t)
{
}

static void insertNode(TreeNode *t)
{
    switch (t->nodekind) {
        case (StmtK):
            break;
        case (ExpK):
            break;
        case (DeclK):
            break;
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
    traverse(t, insertNode, nullProc);
    printSymtab(listing);

}

void typeCheck(TreeNode *t)
{
    traverse(t, nullProc, checkNode);

}
