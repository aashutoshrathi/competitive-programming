// April 2
int numSquareSum(int n) {
    int squareSum = 0;
    while (n) {
        squareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return squareSum;
}

bool isHappy(int n) {
    while (1) {
        if (n == 1)
            return true;
        n = numSquareSum(n);
        if (n == 4)
            return false;
    }

    return false;
}