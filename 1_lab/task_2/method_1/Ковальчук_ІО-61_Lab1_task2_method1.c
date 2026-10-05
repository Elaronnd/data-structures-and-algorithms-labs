#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
    int x;
    double result = 0;
    bool is_calculated = false;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    if (x < -19) {
        is_calculated = true;
        result = 2 * pow(x, 3) + 8 * pow(x, 2);
    } else if (x > -3) {
        if (x <= 0) {
            is_calculated = true;
            result = 2 * pow(x, 3) + 8 * pow(x, 2);
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