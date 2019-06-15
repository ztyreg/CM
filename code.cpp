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
    int savedLoc1, savedLoc2, currentLoc;
    int loc;
    switch (t->kind.stmt) {
        case CompK:
            cout << "... comp" << endl;
//            symtab = enterScope(symtab);
//            generateCode(t);


            break;

        case IfK :
            cout << "... if" << endl;
//            emitComment("-> if");
//            p1 = t->child[0];
//            p2 = t->child[1];
//            p3 = t->child[2];
//            /* generate code for test expression */
//            generateCode(p1, symtab);
//            savedLoc1 = emitSkip(1);
//            emitComment("if: jump to else belongs here");
//            /* recurse on then part */
//            generateCode(p2, symtab);
//            savedLoc2 = emitSkip(1);
//            emitComment("if: jump to end belongs here");
//            currentLoc = emitSkip(0);
//            emitBackup(savedLoc1);
//            emitRM_Abs("JEQ", ac, currentLoc, "if: jmp to else");
//            emitRestore();
//            /* recurse on else part */
//            generateCode(p3, symtab);
//            currentLoc = emitSkip(0);
//            emitBackup(savedLoc2);
//            emitRM_Abs("LDA", pc, currentLoc, "jmp to end");
//            emitRestore();
//            emitComment("<- if");
//            break; /* if_k */

        case RepeatK:
//            emitComment("-> repeat");
//            p1 = t->child[0];
//            p2 = t->child[1];
//            savedLoc1 = emitSkip(0);
//            emitComment("repeat: jump after body comes back here");
//            /* generate code for body */
//            generateCode(p1, symtab);
//            /* generate code for test */
//            generateCode(p2, symtab);
//            emitRM_Abs("JEQ", ac, savedLoc1, "repeat: jmp back to body");
//            emitComment("<- repeat");
//            break; /* repeat */

        case AssignK:
            cout << "... assign" << endl;
//            emitComment("-> assign");
//            /* generate code for rhs */
//            generateCode(t->child[0], symtab);
//            /* now store value */
//            loc = st_lookup(t->attr.name);
//            emitRM("ST", ac, loc, gp, "assign: store value");
//            emitComment("<- assign");
//            break; /* assign_k */

        default:
            cout << t->kind.stmt << endl;
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
//            emitComment("-> Id");
//            loc = st_lookup(t->attr.name);
//            emitRM("LD", ac, loc, gp, "load id value");
//            emitComment("<- Id");
//            break; /* IdK */

        case OpK :
//            emitComment("-> Op");
//            p1 = t->child[0];
//            p2 = t->child[1];
//            /* gen code for ac = left arg */
//            generateCode(p1, symtab);
//            /* gen code to push left operand */
//            emitRM("ST", ac, tmpOffset--, mp, "op: push left");
//            /* gen code for ac = right operand */
//            generateCode(p2, symtab);
//            /* now load left operand */
//            emitRM("LD", ac1, ++tmpOffset, mp, "op: load left");
//            switch (t->attr.op) {
//                case PLUS :
//                    emitRO("ADD", ac, ac1, ac, "op +");
//                    break;
//                case MINUS :
//                    emitRO("SUB", ac, ac1, ac, "op -");
//                    break;
//                case TIMES :
//                    emitRO("MUL", ac, ac1, ac, "op *");
//                    break;
//                case OVER :
//                    emitRO("DIV", ac, ac1, ac, "op /");
//                    break;
//                case LT :
//                    emitRO("SUB", ac, ac1, ac, "op <");
//                    emitRM("JLT", ac, 2, pc, "br if true");
//                    emitRM("LDC", ac, 0, ac, "false case");
//                    emitRM("LDA", pc, 1, pc, "unconditional jmp");
//                    emitRM("LDC", ac, 1, ac, "true case");
//                    break;
//                case EQ :
//                    emitRO("SUB", ac, ac1, ac, "op ==");
//                    emitRM("JEQ", ac, 2, pc, "br if true");
//                    emitRM("LDC", ac, 0, ac, "false case");
//                    emitRM("LDA", pc, 1, pc, "unconditional jmp");
//                    emitRM("LDC", ac, 1, ac, "true case");
//                    break;
//                default:
//                    emitComment("BUG: Unknown operator");
//                    break;
//            } /* case op */
//            emitComment("<- Op");
            break; /* OpK */

        default:
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
    code << "# CM P-CODE" << endl;

    generateCode(t);

}

CodeGenerator::CodeGenerator(Scope *symtab) : symtab(symtab)
{}

