//
// Created by y on 2019-06-15.
//

#include <iostream>
#include "code.h"
#include "codeUtil.h"
#include "tiny.tab.h"
#include "symtab.h"

int tmpOffset = 0;

void CodeGenerator::genStmt(TreeNode *t)
{
    cout << "stmt" << endl;
    TreeNode *p1, *p2, *p3;
    int savedLoc1, savedLoc2, savedLoc3, currentLoc;
    int loc;
    switch (t->kind.stmt) {
        case CompK:
            cout << "... comp" << endl;
            /* enter scope */
            symtab = enterFirstScope(symtab);
            emitComment("-> comp");
            p1 = t->child[0];
            p2 = t->child[1];
            generateCode(p1);
            generateCode(p2);
            emitComment("<- comp");
            /* exit scope */
            symtab = exitScopeSetNull(symtab);
            break;

        case IfK :
            cout << "... if" << endl;
            emitComment("-> if");
            p1 = t->child[0];
            p2 = t->child[1];
            p3 = t->child[2];
            /* generate code for test expression */
            generateCode(p1);
            savedLoc1 = emitSkip(1);
            emitComment("if: jump to else belongs here");
            /* recurse on then part */
            generateCode(p2);
            savedLoc2 = emitSkip(1);
            emitComment("if: jump to end belongs here");
            currentLoc = emitSkip(0);
            emitBackup(savedLoc1);
            emitRM_Abs("JEQ", ac, currentLoc, "if: jmp to else");
            emitRestore();
            /* recurse on else part */
            generateCode(p3);
            currentLoc = emitSkip(0);
            emitBackup(savedLoc2);
            emitRM_Abs("LDA", pc, currentLoc, "jmp to end");
            emitRestore();
            emitComment("<- if");
            break; /* if_k */

        case AssignK:
            cout << "... assign" << endl;
            emitComment("-> assign");
            /* generate code for rhs */
            generateCode(t->child[1]);
            /* now store value */
            loc = findLoc(t->attr.name, symtab);
            if (t->child[0]->sibling != NULL) {
                cout << "... ... int*" << endl;
                loc += t->child[0]->sibling->attr.val;
                cout << "... ... ... "
                     << t->child[0]->sibling->attr.val << endl;
                emitRM("ST", ac, loc, gp, "assign: store value");
            } else {
                cout << "... ... int" << endl;
                emitRM("ST", ac, loc, gp, "assign: store value");
            }
            emitComment("<- assign");
            break; /* assign_k */
        case ItrK:
            cout << "... while" << endl;
            emitComment("-> while");
            p1 = t->child[0];
            p2 = t->child[1];
            /* generate code for test expression */
            savedLoc1 = emitSkip(0);
            emitComment("while: test start");
            generateCode(p1);

            savedLoc2 = emitSkip(1);
            emitComment("while: body start");
            generateCode(p2);

            savedLoc3 = emitSkip(1);
            currentLoc = emitSkip(0);

            emitBackup(savedLoc2);
            emitRM_Abs("JEQ", ac, currentLoc, "while: to end");
            emitRestore();

            emitBackup(savedLoc3);
            emitRM_Abs("LDA", pc, savedLoc1, "jmp to end");
            emitRestore();

//            /* while test */
//            p1 = t->child[0];
//            /* while body */
//            p2 = t->child[1];
//            /* generate code for test */
//            savedLoc1 = emitSkip(1);
//            emitComment("while: jump after body comes back here");
//            generateCode(p1);
//            savedLoc2 = emitSkip(1);
//            /* generate code for body */
//            generateCode(p2);
//            emitRM_Abs("LDA", pc, savedLoc1, "jmp to test");
//            currentLoc = emitSkip(0);
//            emitBackup(savedLoc2);
//            emitRM_Abs("JEQ", ac, currentLoc, "while: jmp to end");
//            emitRestore();
            emitComment("<- while");
            break; /* repeat */
        case RetK:
            cout << "... return" << endl;
            break;
        case CallK:
            cout << "... call" << endl;
            /* predefine output() */
            if (string(t->attr.name) == "output") {
                cout << "... ... output" << endl;
                /* generate code for expression to write */
                generateCode(t->child[1]);
                /* now output it */
                emitRO("OUT", ac, 0, 0, "write ac");
            } else {

            }
            break;


        default:
            cout << "unknown stmt " << t->kind.stmt << endl;
            break;
    }
}

/* Procedure genExp generates code at an expression node */
void CodeGenerator::genExp(TreeNode *t)
{
    cout << "exp" << endl;
    int loc;
    TreeNode *p1, *p2;
    switch (t->kind.exp) {

        case ConstK :
            cout << "... const" << endl;
            emitComment("-> Const");
            /* gen code to load integer constant using LDC */
            emitRM("LDC", ac, t->attr.val, 0, "load const");
            emitComment("<- Const");
            break; /* ConstK */

        case IdK :
            cout << "... id" << endl;
            emitComment("-> Id");
            loc = findLoc(t->attr.name, symtab);
            emitRM("LD", ac, loc, gp, "load id value");
            emitComment("<- Id");
            break; /* IdK */

        case OpK :
            cout << "... op" << endl;
            emitComment("-> Op");
            p1 = t->child[0];
            p2 = t->child[1];
            /* gen code for ac = left arg */
            generateCode(p1);
            /* gen code to push left operand */
            emitRM("ST", ac, tmpOffset--, mp, "op: push left");
            /* gen code for ac = right operand */
            generateCode(p2);
            /* now load left operand */
            emitRM("LD", ac1, ++tmpOffset, mp, "op: load left");
            switch (t->attr.op) {
                case PLUS :
                    cout << "... ... +" << endl;
                    emitRO("ADD", ac, ac1, ac, "op +");
                    break;
                case MINUS :
                    cout << "... ... -" << endl;
                    emitRO("SUB", ac, ac1, ac, "op -");
                    break;
                case TIMES :
                    cout << "... ... *" << endl;
                    emitRO("MUL", ac, ac1, ac, "op *");
                    break;
                case OVER :
                    cout << "... ... /" << endl;
                    emitRO("DIV", ac, ac1, ac, "op /");
                    break;
                case LT :
                    cout << "... ... <" << endl;
                    emitRO("SUB", ac, ac1, ac, "op <");
                    emitRM("JLT", ac, 2, pc, "br if true");
                    emitRM("LDC", ac, 0, ac, "false case");
                    emitRM("LDA", pc, 1, pc, "unconditional jmp");
                    emitRM("LDC", ac, 1, ac, "true case");
                    break;
                case GT :
                    cout << "... ... >" << endl;
                    emitRO("SUB", ac, ac1, ac, "op >");
                    emitRM("JGT", ac, 2, pc, "br if true");
                    emitRM("LDC", ac, 0, ac, "false case");
                    emitRM("LDA", pc, 1, pc, "unconditional jmp");
                    emitRM("LDC", ac, 1, ac, "true case");
                    break;
                case EQ_OP :
                    cout << "... ... +" << endl;
                    emitRO("SUB", ac, ac1, ac, "op ==");
                    emitRM("JEQ", ac, 2, pc, "br if true");
                    emitRM("LDC", ac, 0, ac, "false case");
                    emitRM("LDA", pc, 1, pc, "unconditional jmp");
                    emitRM("LDC", ac, 1, ac, "true case");
                    break;
                case LE_OP :
                    cout << "... ... +" << endl;
                    emitRO("SUB", ac, ac1, ac, "op <=");
                    emitRM("JLE", ac, 2, pc, "br if true");
                    emitRM("LDC", ac, 0, ac, "false case");
                    emitRM("LDA", pc, 1, pc, "unconditional jmp");
                    emitRM("LDC", ac, 1, ac, "true case");
                    break;
                case GE_OP :
                    cout << "... ... +" << endl;
                    emitRO("SUB", ac, ac1, ac, "op >=");
                    emitRM("JGE", ac, 2, pc, "br if true");
                    emitRM("LDC", ac, 0, ac, "false case");
                    emitRM("LDA", pc, 1, pc, "unconditional jmp");
                    emitRM("LDC", ac, 1, ac, "true case");
                    break;
                case NE_OP :
                    cout << "... ... +" << endl;
                    emitRO("SUB", ac, ac1, ac, "op !=");
                    emitRM("JNE", ac, 2, pc, "br if true");
                    emitRM("LDC", ac, 0, ac, "false case");
                    emitRM("LDA", pc, 1, pc, "unconditional jmp");
                    emitRM("LDC", ac, 1, ac, "true case");
                    break;
                default:
                    emitComment("BUG: Unknown operator");
                    break;
            } /* case op */
            emitComment("<- Op");
            break; /* OpK */

        default:
            cout << "unknown exp " << t->kind.stmt << endl;
            break;
    }
} /* genExp */

void CodeGenerator::generateCode(TreeNode *t)
{
    if (t != NULL) {
        switch (t->nodekind) {
            case StmtK:
                genStmt(t);
                break;
            case ExpK:
                genExp(t);
                break;
            default:
                break;
        }
        generateCode(t->sibling);
    }

}

void CodeGenerator::generateCodeDriver(TreeNode *t)
{
    cout << "\nGenerate code start ..." << endl;
    emitComment("C Minus Compilation to TM Code");
    /* generate standard prelude */
    emitComment("Standard prelude:");
    emitRM("LD", mp, 0, ac, "load maxaddress from location 0");
    emitRM("ST", ac, 0, ac, "clear location 0");
    emitComment("End of standard prelude.");

    generateCode(t);

    emitComment("End of execution.");
    emitRO("HALT", 0, 0, 0, "");

}

CodeGenerator::CodeGenerator(Scope *symtab) : symtab(symtab)
{}

