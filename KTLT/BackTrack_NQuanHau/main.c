#include <stdio.h>

int N;
int X[50];
int cot[50], d1[100], d2[100];

void inkq() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (X[i] == j) printf("1");
            else printf("0");
        }
        printf("\n");
    }
    printf("\n");
}

void Try(int i) {
    for (int j = 1; j <= N; j++) {
        if (cot[j] == 0 && d1[i - j + N] == 0 && d2[i + j - 1] == 0) {

            cot[j] = d1[i - j + N] = d2[i + j - 1] = 1;
            X[i] = j;

            if (i == N)
                inkq();
            else
                Try(i + 1);

            cot[j] = d1[i - j + N] = d2[i + j - 1] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) cot[i] = 0;
    for (int i = 0; i <= 2 * N-1; i++) d1[i] = d2[i] = 0;

    Try(1);

    return 0;
}
