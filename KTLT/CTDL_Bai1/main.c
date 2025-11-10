#include <stdio.h>
#include <stdlib.h>
void nhapPhanTu(int n, int a[]){
    printf("Nhap cac phan tu:\n");
    for(int i=0; i<n; i++){
        do{
        printf("a[%d]=", i+1);
        scanf("%d", &a[i]);
        if(a[i]<0){
            printf("Vui long nhap lai la so nguyen duong\n");
        }
        }while(a[i]<0);
    }
}
void inDay(int n, int a[]){
    printf("[");
    for(int i=0; i<n; i++){
            printf("%d\t", a[i]);
    }
    printf("]\n");
}
int kiemTraSNT(int x){
   if(x<2){
    return 0;
   }
   if(x==2){
    return 1;
   }
   if(x%2==0){
    return 0;
   }
   for(int i=2; i<=sqrt(x); i++){
    if(x%i==0){
        return 0;
    }
   }
   return 1;
}
void inSONT(int n, int a[]){
    int count=0;
    printf("Cac so nguyen to co trong mang la:\n");
    printf("[");
    for(int i=0; i<n; i++){
        if(kiemTraSNT(a[i])){
            printf("%d\t", a[i]);
            count++;
        }
    }
    if(count==0){
        printf("Khong co so nguyen to\n");
    }
     printf("]\n");
}
void inSoChinhPhuong(int n, int a[]){
    printf("Cac so chinh phuong la:\n");
    printf("[");
    int count=0;
    for(int i=0; i<n; i++){
    int can=sqrt(a[i]);
    if(a[i]==can*can){
        printf("%d\t", a[i]);
        count++;
        }
    }
    if(count==0){
        printf("Khong co so chinh phuong\n");
    }
    printf("]\n");
}
int kiemTraDoiXung(int n, int a[]){
    for(int i=0; i<(n/2); i++){
        if(a[i]!=a[n-i-1]){
            return 0;
        }
    }
    return 1;
}
int kiemTraMangTang(int n, int a[]){
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1]){
            return 0;
        }
    }
    return 1;
}
int kiemTraMangGiam(int n, int a[]){
    for(int i=0; i<n-1; i++){
        if(a[i]<a[i+1]){
            return 0;
        }
    }
    return 1;
}
void timKiemSoK(int n, int a[]) {
    int k;
    printf("Nhap so nguyen k can tim: ");
    scanf("%d", &k);
    int found = 0;
    printf("Vi tri xuat hien cua %d trong mang: ", k);
    for(int i = 0; i < n; i++) {
        if(a[i] == k) {
            printf("%d ", i);
            found = 1;
        }
    }
    if(found==0) {
        printf("Khong tim thay");
    }
    printf("\n");
}
void sapXepTangDan(int n, int a[]) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int main()
{
   int n;
   do{
   printf("Nhap so luong phan tu (1<n<100):\n");
   scanf("%d", &n);
   if(n<=0 || n>=100){
    printf("Nhap sai so luong! Vui long nhap lai\n");
   }
   }while(n<=0 || n>=100);
   int a[100];
   nhapPhanTu(n,a);
   inDay(n,a);
   inSONT(n,a);
   inSoChinhPhuong(n,a);
   if(kiemTraDoiXung(n,a)){
    printf("Mang doi xung!\n");
   } else {
    printf("Mang khong doi xung\n");
   }
      if(kiemTraMangTang(n,a)){
       printf("Mang tang dan\n");
   } else if(kiemTraMangGiam(n,a)){
       printf("Mang giam dan\n");
   } else {
       printf("Mang khong tang khong giam\n");
   }
   timKiemSoK(n,a);
   sapXepTangDan(n,a);
   inDay(n,a);
}

