#include <stdio.h>
#include <stdlib.h>
int main()
{
   int t;
   scanf("%d", &t);
   while(t--){
    int n;
    scanf("%d", &n);
    int a[51];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int count=1; //3 5 6 8 4 2 9
    for(int i=1; i<n; i++){
        int kiemTra=1;
        for(int j=i-1; j>=0; j--){
            if(a[i]<a[j]){
                kiemTra=0;
                break;
            }
        }
        if(kiemTra!=0){
            count++;
        }
      }
      printf("%d", count);
   }
}
