#include "codeUtil.h"
#include "globals.h"

using namespace std;

/** TM location number for current instruction emission */
static int emitLoc = 0;

/** Highest TM location emitted so far
   For use in conjunction with emitSkip,
   emitBackup, and emitRestore */
static int highEmitLoc = 0;

/** Procedure emitComment prints a comment line
 * with comment c in the code file
 */
void emitComment(string c)
{ code << "# " << c << endl; }

/** Procedure emitRO emits a register-only
 * TM instruction
 * op = the opcode
 * r = target register
 * s = 1st source register
 * t = 2nd source register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRO(string op, int r, int s, int t)
{
    code << emitLoc++ << ": "
         << op << " " << r << "," << s << "," << t << endl;

    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
}

/** Procedure emitRM emits a register-to-memory
 * TM instruction
 * op = the opcode
 * r = target register
 * d = the offset
 * s = the base register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRM(string op, int r, int d, int s)
{
    code << emitLoc++ << ": "
         << op << " " << r << "," << d << "(" << s << ")" << endl;
    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
}

/** Function emitSkip skips "howMany" code
 * locations for later backpatch. It also
 * returns the current code position
 */
int emitSkip(int howMany)
{
    int i = emitLoc;
    emitLoc += howMany;
    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
    return i;
}

/** Procedure emitBackup backs up to
 * loc = a previously skipped location
 */
void emitBackup(int loc)
{
    if (loc > highEmitLoc) emitComment("BUG in emitBackup");
    emitLoc = loc;
}

/** Procedure emitRestore restores the current
 * code position to the highest previously
 * unemitted position
 */
void emitRestore(void)
{ emitLoc = highEmitLoc; }

/** Procedure emitRM_Abs converts an absolute reference
 * to a pc-relative reference when emitting a
 * register-to-memory TM instruction
 * op = the opcode
 * r = target register
 * a = the absolute location in memory
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRM_Abs(string op, int r, int a, string c)
{
    code << emitLoc << ": "
         << op << " " << r << "," << a-(emitLoc+1)
         << "(" << pc << ")" << endl;
    ++emitLoc;
    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
}
