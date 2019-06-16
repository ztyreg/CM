/****************************************************/
/* File: main.c                                     */
/* Main program for TINY compiler                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "tiny.tab.h"

#include "util.h"
#include "scan.h"
#include "parse.h"
#include "analyze.h"
#include "code.h"


/* allocate global variables */
FILE *source;
FILE *listing;
ofstream code;

int Error = FALSE;


int main(void)
{
    listing = stdout;
    const char *sFile = "test.c";
    FILE *fp = fopen(sFile, "r");
    if (fp == NULL) {
        printf("cannot open %s\n", sFile);
        return -1;
    }

    // parse
    extern FILE *yyin;
    yyin = fp;
    printf("Parse %s start\n", sFile);
    TreeNode *t;
    t = parse();
    printTree(t);


    // analyze
    Scope *program;
    program = buildSymtab(t);
    printSymtab(program);

    // code
    code.open("test.asm", ios::out | ios::trunc);
    CodeGenerator generator(program);
    generator.generateCodeDriver(t);

    return 0;

}

