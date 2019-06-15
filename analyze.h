//
// Created by y on 2019-06-08.
//

#ifndef CM_ANALYZE_H
#define CM_ANALYZE_H

#include "globals.h"
#include "symtab.h"

Symtab buildSymtab(TreeNode *t);

void typeCheck(TreeNode * t);

#endif //CM_ANALYZE_H
