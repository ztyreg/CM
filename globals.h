#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <vector>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define VERBOSE 1
#define MAXRESERVED 8


using namespace std;

typedef int TokenType;

extern FILE *source; /* source code text file */
extern FILE *listing; /* listing output text file */
extern std::ofstream code; /* code text file for TM simulator */
//int lineno=0; /* source line number for listing */
extern int lineno;

/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum {
    StmtK, ExpK, DeclK
} NodeKind;
/* not used: repeat, read, write */
typedef enum {
    IfK, RepeatK, AssignK, ReadK, WriteK, CompK, ItrK, RetK, CallK
} StmtKind;
typedef enum {
    OpK, ConstK, IdK, TypeK
} ExpKind;
typedef enum {
    VarK, FuncK
} DeclKind;

/* ExpType is used for type checking */
typedef enum {
    Void, Integer, Boolean
} ExpType;

#define MAXCHILDREN 4

typedef struct treeNode {
    struct treeNode *child[MAXCHILDREN];
    struct treeNode *sibling;
    int lineno;
    NodeKind nodekind;
    union {
        StmtKind stmt;
        ExpKind exp;
        DeclKind decl;
    } kind;
    struct {
        TokenType op;
        int val;
        char *name;
        char *type;
    } attr;
    ExpType type; /* for type checking of exps */
} TreeNode;

/**************************************************/
/****************   Symbol table ******************/
/**************************************************/

class Symbol {
public:
    string name;
    string type;
    int location; //memory location
    int length;
    vector<int> lineno; //occurrences

};

class Scope {
private:

public:
    Scope() : outer(NULL) {}
    vector<Symbol *> symbols;
    Scope *outer;
    vector<Scope *> inner;
};

extern int Error;

#endif
