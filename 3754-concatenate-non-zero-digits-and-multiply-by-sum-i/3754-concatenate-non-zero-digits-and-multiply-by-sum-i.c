long long sumAndMultiply(int n) {
    int digits[11];
    int count = 0;
    int sum = 0;
    long long x = 0;

    if (n == 0) return 0;

    while (n > 0) {
        int d = n % 10;
        if (d != 0) {
            digits[count++] = d;
        }
        n /= 10;
    }

    for (int i = count - 1; i >= 0; i--) {
        x = x * 10 + digits[i];
        sum += digits[i];
    }

    return x * sum;
}
