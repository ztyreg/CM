#include "codeUtil.h"
#include "globals.h"

using namespace std;

/** TM location number for current instruction emission */
static int emitLoc = 0;

/** Highest TM location emitted so far
   For use in conjunction with emitSkip,
   emitBackup, and emitRestore */
static int highEmitLoc = 0;

void emitComment(string c)
{
    code << "# " << c << endl;
}

void emitRO(string op, int r, int s, int t, string c)
{
    code << emitLoc++ << ": "
         << op << " " << r << "," << s << "," << t
         << "# " << c << endl;

    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
}

void emitRM(string op, int r, int d, int s, string c)
{
    code << emitLoc++ << ": "
         << op << " " << r << "," << d << "(" << s << ")"
         << "# " << c << endl;
    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
}

int emitSkip(int howMany)
{
    int i = emitLoc;
    emitLoc += howMany;
    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
    return i;
}

void emitBackup(int loc)
{
    if (loc > highEmitLoc) emitComment("BUG in emitBackup");
    emitLoc = loc;
}

void emitRestore(void)
{ emitLoc = highEmitLoc; }

void emitRM_Abs(string op, int r, int a, string c)
{
    code << emitLoc << ": "
         << op << " " << r << "," << a - (emitLoc + 1)
         << "(" << pc << ")"
         << "# " << c << endl;
    ++emitLoc;
    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
}
