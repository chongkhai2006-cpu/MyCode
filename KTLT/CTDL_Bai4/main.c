#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int a[100];
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        int maxCount=0;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(a[i]==a[j]){
                    count++;
                }
            }
            if(count>maxCount){
                maxCount=count;
            }
        }
        for(int i=0; i<n;i++){
            int count1=0;
            for(int j=0; j<n; j++){
                if(a[j]==a[i]){
                    count1++;
                }
            }
            if(count1==maxCount){
                int daXuatHien=0;
            for(int k=0; k<i; k++){
                    if(a[k]==a[i]){
                        daXuatHien=1;
                        break;
                    }
                }
                if(daXuatHien==0){
                    printf("%d ", a[i]);
                }
            }
        }
        printf("\n");
    }
}

