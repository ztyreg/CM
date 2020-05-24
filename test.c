int x;

int main(void)
{
   int y[6];
   int i;
   int z;

   x = 7;
   if (x > 6) {
       /* output(int x) is predefined */
       output(x); /* 7 */
   }
   if (x > 6) {
       int x;
       x = 10;
       output(x); /* 10 */
   }
   while (x >= 3) {
       x = x - 1;
   }
   output(x); /* 2 */

   i = 0;
   while (i < 6) {
       y[i] = i;
       i = i + 1;
   }
   output(y[5]); /* 5 */
}
