#include <stdio.h>
#include <stdlib.h>
int n;
int *curString;
void in(){
    for(int i=0; i<n; i++)
    printf("%d", curString[i]);
    printf("\n");
}
void sinhChuoi(int pos){
    if(pos==n){
        in();
        return;
    }
    for(int i=0; i<=1; i++){
        curString[pos]=i;
        sinhChuoi(pos+1);
    }
}
int main(){
    scanf("%d", &n);
    curString=(int*)malloc((n+1)*sizeof(int));
    curString[n]='\0';
    sinhChuoi(0);
}

