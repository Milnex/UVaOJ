#include <cstdio>
#include <cmath>
int main()
{
    double a;
    while (scanf("%lf", &a) == 1) {
        double a2 = a*a, sqrt3 = sqrt(3);
        double x = a2*(1 - sqrt3 + M_PI/3);
        double y = a2*(sqrt3/2 + M_PI/12 - 1);
        double z = a2*(1 - M_PI/6 - sqrt3/4);
        printf("%.3lf %.3lf %.3lf\n", x, y*4, z*4);
    }
    return 0;
}