#include <stdio.h>
#include <stdlib.h>
int n,k;
int *a;
void in(){
    for(int i = 1; i <= k; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void sinhToHop(int pos, int start){
    if(pos>k){
        in();
        return;
    }
    for(int i=start+1; i<=n; i++){
        a[pos]=i;
        sinhToHop(pos+1, i);
    }
}
int main()
{
   scanf("%d", &n);
   scanf("%d", &k);
   a=(int*)malloc(k*sizeof(int));
   sinhToHop(1, 0);
   free(a);
   return 0;
}

