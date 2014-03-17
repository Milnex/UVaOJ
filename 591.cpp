#include <cstdio>
#define NMAX  60
int main()
{
    int n, k, num[NMAX];
    for (int i = 1; scanf("%d", &n) && n; i++) {
        int avg = 0, moves = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &num[j]);
            avg += num[j];
        }
        avg /= n;
        for (int j = 0; j < n; j++) 
            if (num[j] < avg)
                moves += avg - num[j];
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", i, moves);
    }
}
