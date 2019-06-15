//
// Created by y on 2019-06-15.
//

#ifndef CM_CODEUTIL_H
#define CM_CODEUTIL_H

/* pc = program counter  */
#define  pc 7

/* mp = "memory pointer" points
 * to top of memory (for temp storage)
 */
#define  mp 6

/* gp = "global pointer" points
 * to bottom of memory for (global)
 * variable storage
 */
#define gp 5

/* accumulator */
#define  ac 0

/* 2nd accumulator */
#define  ac1 1

#include <string>

using namespace std;

/** Procedure emitComment prints a comment line
 * with comment c in the code file
 */
void emitComment(string c);

/** Procedure emitRO emits a register-only
 * TM instruction
 * op = the opcode
 * r = target register
 * s = 1st source register
 * t = 2nd source register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRO(string op, int r, int s, int t, string c);

/** Procedure emitRM emits a register-to-memory
 * TM instruction
 * op = the opcode
 * r = target register
 * d = the offset
 * s = the base register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRM(string op, int r, int d, int s, string c);

/** Function emitSkip skips "howMany" code
 * locations for later backpatch. It also
 * returns the current code position
 */
int emitSkip(int howMany);

/** Procedure emitBackup backs up to
 * loc = a previously skipped location
 */
void emitBackup(int loc);

/** Procedure emitRestore restores the current
 * code position to the highest previously
 * unemitted position
 */
void emitRestore(void);

/** Procedure emitRM_Abs converts an absolute reference
 * to a pc-relative reference when emitting a
 * register-to-memory TM instruction
 * op = the opcode
 * r = target register
 * a = the absolute location in memory
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRM_Abs(string op, int r, int a, string c);

#endif //CM_CODEUTIL_H
