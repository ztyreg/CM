//
// Created by y on 2019-06-08.
//

#include "symtab.h"

void printSymtab(FILE *listing)
{
    int i;
    fprintf(listing, "Var Name Loc Line Numbers Children\n");
    fprintf(listing, "-------- --- ------------ --------\n");
//    for (i = 0; i < SIZE; ++i) {
//        if (hashTable[i] != NULL) {
//            BucketList l = hashTable[i];
//            while (l != NULL) {
//                LineList t = l->lines;
//                fprintf(listing, "%-14s ", l->name);
//                fprintf(listing, "%-8d  ", l->memloc);
//                while (t != NULL) {
//                    fprintf(listing, "%4d ", t->lineno);
//                    t = t->next;
//                }
//                fprintf(listing, "\n");
//                l = l->next;
//            }
//        }
//    }
} /* printSymtab */
