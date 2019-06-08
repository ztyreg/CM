/****************************************************/
/* File: main.c                                     */
/* Main program for TINY compiler                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "tiny.tab.h"

/* set NO_PARSE to TRUE to get a scanner-only compiler */
#define NO_PARSE FALSE
/* set NO_ANALYZE to TRUE to get a parser-only compiler */
#define NO_ANALYZE FALSE

/* set NO_CODE to TRUE to get a compiler that does not
 * generate code
 */
#define NO_CODE FALSE

#include "util.h"
#include "scan.h"
#include "parse.h"
#include "analyze.h"

/* allocate global variables */
//FILE * source;
//FILE * listing;
//FILE * code;

/* allocate and set tracing flags */
int EchoSource = FALSE;
int TraceScan = TRUE;
int TraceParse = TRUE;
int TraceAnalyze = FALSE;
int TraceCode = FALSE;

//int Error = FALSE;

int main()
{
    listing=stdout;
    const char* sFile="test.c";
    FILE* fp=fopen(sFile, "r");
    if(fp==NULL)
    {
        printf("cannot open %s\n", sFile);
        return -1;
    }
    extern FILE* yyin;
    yyin=fp;
    printf("Parse %s start\n",sFile);
    TreeNode * t;
    t=parse();
    printTree(t);


    buildSymtab(t);
    typeCheck(t);

    return 0;
//  TreeNode * syntaxTree;
//  char pgm[120]; /* source code file name */
//  /*if (argc != 2)
//    { fprintf(stderr,"usage: %s <filename>\n",argv[0]);
//      exit(1);
//    }*/
//  printf("Input test file: ");
//  scanf("%s",pgm);
//  if (strchr (pgm, '.') == NULL)
//     strcat(pgm,".c");
//  source = fopen(pgm,"r");
//  if (source==NULL)
//  { fprintf(stderr,"File %s not found\n",pgm);
//    exit(1);
//  }
//  listing = stdout; /* send listing to screen */
//  fprintf(listing,"\nC- COMPILATION: %s\n",pgm);
//#if NO_PARSE
//  while (getToken()!=ENDFILE);
//#else
//  syntaxTree = parse();
//  if (TraceParse) {
//    fprintf(listing,"\nSyntax tree:\n");
//    printTree(syntaxTree);
//  }
//#if !NO_ANALYZE
//  if (! Error)
//  { if (TraceAnalyze) fprintf(listing,"\nBuilding Symbol Table...\n");
//    buildSymtab(syntaxTree);
//    if (TraceAnalyze) fprintf(listing,"\nChecking Types...\n");
//    typeCheck(syntaxTree);
//    if (TraceAnalyze) fprintf(listing,"\nType Checking Finished\n");
//  }
//#if !NO_CODE
//  if (! Error)
//  { char * codefile;
//    int fnlen = strcspn(pgm,".");
//    codefile = (char *) calloc(fnlen+4, sizeof(char));
//    strncpy(codefile,pgm,fnlen);
//    strcat(codefile,".tm");
//    code = fopen(codefile,"w");
//    if (code == NULL)
//    { printf("Unable to open %s\n",codefile);
//      exit(1);
//    }
//    codeGen(syntaxTree,codefile);
//    fclose(code);
//  }
//#endif
//#endif
//#endif
//  fclose(source);
//  return 0;
}

