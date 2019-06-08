/****************************************************/
/* File: globals.h                                  */
/* Global types and vars for TINY compiler          */
/* must come before other include files             */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/* MAXRESERVED = the number of reserved words */
#define MAXRESERVED 8


    /* book-keeping tokens */
//enum TokenType{ERROR,
    /* reserved words */
//    IF,THEN,ELSE,
    /* multicharacter tokens */
//    IDENTIFIER,CONSTANT,
    /* special symbols */
//    EQ,LT,GT,PLUS,MINUS,TIMES,OVER,LPAREN,RPAREN,SEMI,EQ_OP,NE_OP,GE_OP,LE_OP;
//   } ;
typedef int TokenType;

FILE* source; /* source code text file */
FILE* listing; /* listing output text file */
extern FILE* code; /* code text file for TM simulator */
//int lineno=0; /* source line number for listing */
extern int lineno;

/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum {StmtK,ExpK,DeclK} NodeKind;
typedef enum {IfK,RepeatK,AssignK,ReadK,WriteK,CompK,ItrK,RetK,CallK} StmtKind;
typedef enum {OpK,ConstK,IdK,TypeK} ExpKind;
typedef enum {VarK,FuncK} DeclKind;

/* ExpType is used for type checking */
typedef enum {Void,Integer,Boolean} ExpType;

#define MAXCHILDREN 4

typedef struct treeNode {
    struct treeNode * child[MAXCHILDREN];
    struct treeNode * sibling;
    int lineno;
    NodeKind nodekind;
    union { StmtKind stmt; ExpKind exp; DeclKind decl;} kind;
    union { TokenType op;
         int val;
         char * name;
         char * type;} attr;
    ExpType type; /* for type checking of exps */
} TreeNode;

/**************************************************/
/***********   Flags for tracing       ************/
/**************************************************/

/* EchoSource = TRUE causes the source program to
 * be echoed to the listing file with line numbers
 * during parsing
 */
extern int EchoSource;

/* TraceScan = TRUE causes token information to be
 * printed to the listing file as each token is
 * recognized by the scanner
 */
extern int TraceScan;

/* TraceParse = TRUE causes the syntax tree to be
 * printed to the listing file in linearized form
 * (using indents for children)
 */
extern int TraceParse;

/* TraceAnalyze = TRUE causes symbol table inserts
 * and lookups to be reported to the listing file
 */
extern int TraceAnalyze;

/* TraceCode = TRUE causes comments to be written
 * to the TM code file as code is generated
 */
extern int TraceCode;

/* Error = TRUE prevents further passes if an error occurs */
//extern int Error; 
int Error;
#endif
