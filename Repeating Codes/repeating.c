#include <stdio.h>

int main() {
    for (int i = 0, j = 100, k = 1
    i < 10 && j > 50 && (k *= 2) < 1000;
    i++, j -= i*2, k++) {
        printf("i=%d" | j=%d | k"=%d\n", i, j, k);
    }
}