#include <cstdio>
#define N 3010

int main() 
{
    int n, a = 0, b = 0;;
    while (scanf("%d%d", &n, &a) == 2) {
        int jolly[N] = {1, 0};
        for (int i = 1; i < n; i++) {
            scanf("%d", &b);
            jolly[a<b ? b-a : a-b]++;
            a = b;
        }
        for (int i = 1; i < n; i++)
            if (jolly[i] != 1) {
                jolly[0] = 0;
                break;
            }
        printf("%s\n", jolly[0] ? "Jolly" : "Not jolly");
    }
    return 0;
}
