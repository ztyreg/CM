/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */

int yylex(void);
int yyerror(char * message);


%}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token BOOL COMPLEX IMAGINARY
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN ERROR
%token LPAREN RPAREN EQ SEMI GT LT '[' ']' '{' '}'
%left    PLUS MINUS
%left    TIMES OVER
%% /* Grammar for Cminus */
program
	: declaration_list { savedTree = $1; }
	;
declaration_list
	:declaration_list declaration 
	 {YYSTYPE t = $1;
	  if (t != NULL)
	  {while (t->sibling != NULL) t = t->sibling;
	   t->sibling = $2; 
	   $$ = $1;
	  }
	 }
	|declaration { $$ = $1; }
	;
declaration 
	:var_declaration { $$ = $1; }
	|fun_declaration { $$ = $1; }
	;
var_declaration
	:data_type IDENTIFIER SEMI
	{$$ = newDeclNode(VarK);
	  $$->child[0]=$1;
	  $$->child[1]=$2;
	 }
	|data_type IDENTIFIER 
	 '[' CONSTANT ']' SEMI
	 {$$ = newDeclNode(VarK);
	  $$->child[0]=$1;
	  $$->child[1]=$2;
	  $$->child[2]=$4;
	  $$->child[0]->attr.type=(char*)"int*";
	 }
	;
var
	:IDENTIFIER 
	|IDENTIFIER '[' expression ']'
	{$$=$1;
	 $$->sibling = $3;
	 $$->attr.name = $1->attr.name;
	 $$->attr.type=(char*)"int*";
	}
	;
data_type
	:VOID
	{$$ = newExpNode(TypeK);
	 $$->attr.type = (char*)"void";
	}
	|INT
	{$$ = newExpNode(TypeK);
	 $$->attr.type = (char*)"int";
	}
	;
fun_declaration
	:data_type IDENTIFIER LPAREN params RPAREN 
	{$$ = newDeclNode(FuncK);
	  $$->child[0]=$1;
	  $$->child[1]=$2;
	  $$->child[2]=$4;
	 }
	|compound_stmt {$$ = $1;}
	;
params
	:params ',' param
	{YYSTYPE t = $1;
	  if (t != NULL)
	  {while (t->sibling != NULL) t = t->sibling;
	   t->sibling = $3; 
	   $$ = $1;
	  }
	}
	|param {$$ = $1;}
	;
param
	:data_type {$$ = $1;}
	|data_type IDENTIFIER
	{$$ = newDeclNode(VarK);
	 $$->child[0]=$1;
	 $$->child[1]=$2;
	}
	|data_type IDENTIFIER '[' ']'
	{$$ = newDeclNode(VarK);
	 $$->child[0]=$1;
	 $$->child[1]=$2;
	 $$->child[1]->attr.type=(char*)"int*";
	}
	;
compound_stmt
	:'{' local_declarations stmt_list '}'
	{$$ = newStmtNode(CompK);
	 $$->child[0]=$2;
	 $$->child[1]=$3;
	}
	;
local_declarations
	:local_declarations var_declaration
	{YYSTYPE t = $1;
	  if (t != NULL)
	  {while (t->sibling != NULL) t = t->sibling;
	   t->sibling = $2; 
	   $$ = $1;
	  }
	  else
	  {
	   $$=$2;
	  }
	}
	| {$$=NULL;}
	;
stmt_list
	:stmt_list stmt
	{YYSTYPE t = $1;
	  if (t != NULL)
	  {while (t->sibling != NULL) t = t->sibling;
	   t->sibling = $2; 
	   $$ = $1;
	  }
	  else {
	   $$ = $2;
	  }
	}
	|{$$ = NULL;}
	;
stmt
	:expression_stmt { $$ = $1; }
	|selection_stmt { $$ = $1; }
	|iteration_stmt { $$ = $1; }
	|compound_stmt { $$ = $1; }
	|return_stmt { $$ = $1; }
	;
selection_stmt
	:IF LPAREN expression RPAREN stmt 
	{$$ = newStmtNode(IfK);
     $$->child[0] = $3;
     $$->child[1] = $5;
	}
	|IF LPAREN expression RPAREN stmt ELSE stmt
	{$$ = newStmtNode(IfK);
     $$->child[0] = $3;
     $$->child[1] = $5;
     $$->child[2] = $7;
	}
	;
iteration_stmt
	:WHILE LPAREN expression RPAREN stmt
	{$$ = newStmtNode(ItrK);
	 $$->child[0] = $3;
	 $$->child[1] = $5;
	 $$->attr.type = (char*)"WHILE";
	}
	|DO stmt WHILE LPAREN expression RPAREN
	{$$ = newStmtNode(ItrK);
	 $$->child[0] = $2;
	 $$->child[1] = $5;
	 $$->attr.type = (char*)"DO";
	}
	;
return_stmt
	:RETURN SEMI {$$ = newStmtNode(RetK);}
	|RETURN expression SEMI
	{$$ = newStmtNode(RetK);
	 $$->child[0]=$2;
	}
	;
expression_stmt
	:expression SEMI { $$ = $1; }
	|SEMI
	;
expression
	:var EQ expression 
	{$$ = newStmtNode(AssignK);
	 /* name of expression is the same as that of the variable */
	 $$->attr.name=$1->attr.name;
	 $$->child[0]=$1;
	 $$->child[1]=$3;
	}
	|simple_expression { $$ = $1; }
	;
simple_expression
	:math_expression relop math_expression
	{$$ = $2;
	 $$->child[0] = $1;
	 $$->child[1] = $3;
	}
	|math_expression { $$ = $1; }
	;
relop
	:LE_OP {$$ = newExpNode(OpK);$$->attr.op = LE_OP;}
	|GE_OP {$$ = newExpNode(OpK);$$->attr.op = GE_OP;}
	|EQ_OP {$$ = newExpNode(OpK);$$->attr.op = EQ_OP;}
	|NE_OP {$$ = newExpNode(OpK);$$->attr.op = NE_OP;}
	|'>' {$$ = newExpNode(OpK);$$->attr.op = GT;}
	|'<' {$$ = newExpNode(OpK);$$->attr.op = LT;}
	;
math_expression
	:math_expression PLUS term
	{$$ = newExpNode(OpK);
	 $$->child[0] = $1;
	 $$->child[1] = $3;
	 $$->attr.op = PLUS;
	}
	|math_expression MINUS term
	{$$ = newExpNode(OpK);
	 $$->child[0] = $1;
	 $$->child[1] = $3;
	 $$->attr.op = MINUS;
	}
	|term { $$ = $1; }
	;
term
	:term TIMES factor
	{$$ = newExpNode(OpK);
	 $$->child[0] = $1;
	 $$->child[1] = $3;
	 $$->attr.op = TIMES;
	}
	|term OVER factor
	{$$ = newExpNode(OpK);
	 $$->child[0] = $1;
	 $$->child[1] = $3;
	 $$->attr.op = OVER;
	}
	|factor { $$ = $1; }
	;
factor
	:LPAREN expression RPAREN { $$ = $2; }
	|var { $$ = $1; }
	|call { $$ = $1; }
	|CONSTANT { $$ = $1; };
	|ERROR { $$ = NULL; }
	;
call
	:IDENTIFIER LPAREN args RPAREN
	{$$ = newStmtNode(CallK);
	 $$->attr.name=$1->attr.name;
	 $$->child[0]=$1;
	 $$->child[1]=$3;
	}
	;
args
	:arg_list { $$ = $1; }
	| { $$ = NULL; }
	;
arg_list
	:arg_list ',' expression
	{YYSTYPE t = $1;
	  if (t != NULL)
	  {while (t->sibling != NULL) t = t->sibling;
	   t->sibling = $3; 
	   $$ = $1;
	  }
	}
	|expression { $$ = $1; }
	;

%%
extern int column;
int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d column %d: %s\n",lineno,column,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 
int yylex(void)
{ return getToken(); }*/

TreeNode * parse(void)
{ yyparse();
  printf("parse end\n");
  return savedTree;
}

