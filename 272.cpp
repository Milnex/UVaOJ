#include <cstdio>
int main()
{
    int c, left = 1;
    while ((c = fgetc(stdin)) != EOF) {
        if (c == '"') {
            printf("%s", left ? "``" : "''");
            left = !left;
        }
        else
            printf("%c", c);
    }
    return 0;
}
