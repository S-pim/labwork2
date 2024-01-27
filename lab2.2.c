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
double model (double term){
    if (term<0){
        term*=(-1);
    }
    return term;
}

double series(double x, double eps) {
    double sum = 0;
    int n=0;
    double term = 1;
    while (model(term)>eps) {
        n++;
        sum += term;
        term = twotothedegree(n) * cos(n * 3.14 / 4) * xtothedegree(x, n) / factorial(n);
    }
    printf("terms quantity %d\n",n);
    return sum;
}
double ex_cos_x(double x) {
    return exp(x) * cos(x);
}
int main() {
    double x;
    double eps;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the eps ");
    scanf("%lf", &eps);

    double result = series(x, eps);
    double ex_cos_x_result = ex_cos_x(x);
    printf("Result with %lf series terms: %lf\n", eps, result);
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
