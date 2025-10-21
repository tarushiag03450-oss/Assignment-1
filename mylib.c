#include <stdio.h>
#include <math.h>
#include "mylib.h"

// #Cp

int reverseDigits(int n) {
    int r = 0;
    while (n > 0) {
        r = r * 10 + (n % 10);
        n /= 10;
    }
    return r;
}

int isArmstrong(int num) {
    int original = num;
    int sum = 0, temp = num, digits = 0;

    // Count digits
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = num;

    // Calculate sum of each digit raised to the power of digits
    while (temp > 0) {
        int d = temp % 10;
        double powered = pow(d, digits);
        sum += (int)(powered + 0.5);  // ✅ rounding fix
        temp /= 10;
    }

    return sum == original;
}

int isAdams(int num) {
    int sq = num * num;
    int revNum = reverseDigits(num);
    int revSq = revNum * revNum;
    return reverseDigits(sq) == revSq;
}

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int isPrimePalindrome(int num) {
    return isPrime(num) && (num == reverseDigits(num));
}
