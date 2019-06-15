//
// Created by y on 2019-06-15.
//

#ifndef CM_CODE_H
#define CM_CODE_H

#include "globals.h"
#include <string>

using namespace std;

class CodeGenerator {
private:
    Scope *symtab;

public:
    explicit CodeGenerator(Scope *symtab);

    void generateCodeDriver(TreeNode *t);

    void generateCode(TreeNode *t);

    void genStmt(TreeNode *t);

    void genExp(TreeNode *t);
};

#endif //CM_CODE_H
