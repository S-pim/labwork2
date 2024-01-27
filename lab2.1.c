#include <stdio.h>
#include <math.h>

double twotothedegree(int n) {
    double a = 1;

    for (int i = 0; i < n / 2; i++) {
        a *= 2;
    }

    if (n % 2 != 0) {
        a *= sqrt(2);
    }

    return a;
}

double xtothedegree(double x, int n) {
    double b = 1.0;

    for (int i = 0; i < n; ++i) {
        b *= x;
    }

    return b;
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

double series(double x, int numTerms) {
    double sum = 0;

    for (int n = 0; n <= numTerms; n++) {
        double term = twotothedegree(n) * cos(n * 3.14 / 4) * xtothedegree(x, n) / factorial(n);
        sum += term;
    }

    return sum;
}
double ex_cos_x(double x) {
    return exp(x) * cos(x);
}
int main() {
    double x;
    int numTerms;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the number of series terms: ");
    scanf("%d", &numTerms);

    double result = series(x, numTerms);
    double ex_cos_x_result = ex_cos_x(x);
    printf("Result with %d series terms: %lf\n", numTerms, result);
    printf("e^x * cos(x) result: %lf\n", ex_cos_x_result);

    if (result > ex_cos_x_result) {
        printf("Series result is greater than e^x * cos(x)\n");
    } else if (result < ex_cos_x_result) {
        printf("Series result is less than e^x * cos(x)\n");
    } else {
        printf("Series result is equal to e^x * cos(x)\n");
    }

    return 0;
}
