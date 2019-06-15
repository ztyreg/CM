//
// Created by y on 2019-06-15.
//

#ifndef CM_CODEUTIL_H
#define CM_CODEUTIL_H

#define pc 7

#include <string>

using namespace std;

void emitComment(string c);

void emitRO(string op, int r, int s, int t);

void emitRM(string op, int r, int d, int s);

int emitSkip(int howMany);

void emitBackup(int loc);

void emitRestore(void);

void emitRM_Abs(string op, int r, int a, string c);

#endif //CM_CODEUTIL_H
