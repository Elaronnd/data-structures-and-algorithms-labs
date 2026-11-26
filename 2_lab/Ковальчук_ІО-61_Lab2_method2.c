#include <stdio.h>

#define PI 3.14159265358979323846


int main(void)
{
    int n;
    const double x = 1.0 / 3.0;
    const double pi2 = PI * PI;
    const double four_x2 = 4.0 * x * x;
    double product = 1.0;
    double square = 1.0;
    long long ops = 0;

    printf("n = ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Error: n must be a natural number.\n");
        return 1;
    }

    ops += 9;
    ops += 1;

    for (int i = 1; i <= n; i++) {
        ops += 2;
        double factor = 1.0 - four_x2 / (pi2 * square);
        ops += 4;
        product *= factor;
        ops += 2;
        square += 8.0 * i;
        ops += 3;
    }
    ops += 1;

    printf("P = %.7f\n", product);
    printf("Operations: %lld\n", ops);
    return 0;
}
