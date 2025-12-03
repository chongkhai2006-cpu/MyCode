#include <stdio.h>
#include <stdlib.h>

int n;
int *a;
long long S;
long long curMoneySum;
int *curMoneySet;

void printMoneySet(int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", a[curMoneySet[i]]);
    }
    printf("\n");
}

void backTrack(int pos, int start) {
    if(curMoneySum == S) {
        printMoneySet(pos);
        return;
    }
    if(curMoneySum > S) return;

    for(int i = start; i <= n; i++) {
        curMoneySet[pos] = i;
        curMoneySum += a[i];
        backTrack(pos + 1, i);
        curMoneySum -= a[i];
    }
}

int main() {
    scanf("%d %lld", &n, &S);

    a = (int*) malloc((n + 1) * sizeof(int));
    curMoneySet = (int*) malloc((S + 1) * sizeof(int));

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    curMoneySum = 0;
    backTrack(0, 1);

    free(a);
    free(curMoneySet);
    return 0;
}
