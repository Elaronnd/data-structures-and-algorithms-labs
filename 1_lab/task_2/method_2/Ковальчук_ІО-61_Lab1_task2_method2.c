#include <stdio.h>
#include <math.h>

int main(void) {
    int x;

    printf("Enter the value of x: ");

    scanf("%d", &x);

    if (x < -19 || (x > -3 && x <= 0)) {
        printf("%f\n", 2 * pow(x, 3) + 8 * pow(x, 2));
    } else {
        printf("The function is not defined for the given x");
    }
    return 0;
}
