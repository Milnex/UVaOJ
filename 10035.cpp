#include <cstdio>
#include <cstring>
#include <algorithm>
#define DIGITS 20

unsigned computeCarries(char *a, char *b) 
{
    std::reverse(a, a+strlen(a));
    std::reverse(b, b+strlen(b));
    int carryCount = 0, carry = 0, ci = 0;
    char c[DIGITS] = "";
    while (*a || *b || carry) {
        int d1 = *a ? *a-'0' : 0;
        int d2 = *b ? *b-'0' : 0;
        int d = d1 + d2 + carry;
        c[ci++] = d%10 + '0';
        carry = d/10;
        if (d > 9) carryCount++;
        if (*a) a++;
        if (*b) b++;
    }
    return carryCount;
}

int main() 
{
    char A[DIGITS], B[DIGITS];
    while (scanf("%s%s", A, B) == 2 && (strcmp(A, "0") || strcmp(B, "0"))) {
        int carries = computeCarries(A, B);
        if (carries != 0)
            printf("%d carry operation%s\n", carries, carries > 1 ? "s." : ".");
        else
            printf("No carry operation.\n");
    }
    return 0;
}
