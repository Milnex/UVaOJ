#include <cstdio>
const char *table = ".........\t\n..\r.................. ......;....M0,.9`12345678.L.-....VXSWDFGUHJKNBIO.EARYCQZT.P][......";
int main()
{
    int c;
    while ((c = fgetc(stdin)) != EOF)
        fputc(table[c], stdout);
    return 0;
}
