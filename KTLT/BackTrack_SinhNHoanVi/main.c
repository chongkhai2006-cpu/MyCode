#include <stdio.h>
#include <stdlib.h>

int n;
int *a;
int *used;

void in(){
    for(int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void sinhHoanVi(int pos){
    if(pos > n){
        in();
        return;
    }
    for(int i = 1; i <= n; i++){
        if(used[i] == 0){
            used[i] = 1;
            a[pos] = i;
            sinhHoanVi(pos + 1);
            used[i] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    used = (int*)malloc((n+1) * sizeof(int));
    a = (int*)malloc((n+1) * sizeof(int));
    for(int i = 1; i <= n; i++){
        used[i] = 0;
    }
    sinhHoanVi(1);
    free(a);
    free(used);
    return 0;
}
