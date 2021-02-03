double getAbsoluteValue(double number) {
    return number >= 0 ? number : -number;
}

double sqrt_a(double a, double eps) {
    double x = a;

    while (true) {
        double nextX = 0.5 * (x + a / x);

        if(getAbsoluteValue(nextX - x) < eps) {
            x = nextX;
            break;
        }

        x = nextX;
    }

    return x;
}