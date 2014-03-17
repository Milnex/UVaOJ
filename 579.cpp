#include <cstdio>
#include <cmath>
int main()
{
    int H, M;
    while (scanf("%d:%d", &H, &M) == 2 && (H || M)) {
        float angle = fabs(30*H - 5.5*M);
        float cangle = 360 - angle;
        printf("%.3f\n", angle < cangle ? angle : cangle);
    }
    return 0;
}
