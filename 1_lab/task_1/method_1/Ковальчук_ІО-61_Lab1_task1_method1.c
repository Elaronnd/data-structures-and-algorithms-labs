#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
    int x;
    double result = 0;
    bool is_calculated = false;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    if (x >= 8) {
        if (x < 23) {
            is_calculated = true;
            result = -5 * pow(x, 3) + 10;
        }
    }

    if (is_calculated) {
        printf("%f\n", result);
    }
    else {
        printf("The function is not defined for the given x");
    }

    return 0;
}