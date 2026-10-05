#include <stdio.h>
#include <math.h>

int main(void) {
    int x;

    printf("Enter the value of x: ");

    scanf("%d", &x);

    if (x >= 8 && x < 23) {
        printf("%f\n", -5 * pow(x, 3) + 10 );
    } else {
        printf("The function is not defined for the given x");
    }
    return 0;
}
