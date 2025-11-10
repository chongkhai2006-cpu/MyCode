#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
int demKhoangTrang(char str[]){
    int count=0;
    int doDai=strlen(str);
    for(int i=0; i<doDai; i++){
        if(str[i]==' '){
            count++;
        }
    }
    return count;
}
void loaiKhoangTrang(char str[]){
    int doDai=strlen(str);
    for(int i=0; i<doDai; i++){
        if(str[i]==' '){
            for(int j=i; j<' '; j++){
                str[j]=str[j+1];
            }
            i--;
            doDai--;
        }
    }
}
void noiHaiChuoi(char str[], char str2[]){
    int i=0, j=0;
    while(str[i] !='\0'){
        i++;
    }
    str[i]=' ';
    i++;
    while(str2[j]!=0){
        str[i]=str2[j];
        i++;
        j++;
    }
}
void chuyenChuoiHoaTuDau(char str[]){
    int i=0;
    if(str[0]>='a' && str[0]<='z'){
        str[0]=str[0]-32;
    }
    while(str[i]!='\0'){
        if(str[i]==' ' && str[i+1]>='a' && str[i+1]<='z'){
            str[i+1]=str[i+1]-32;
        }
        i++;
    }
}
void display() {
    printf("\n===== CHUONG TRINH XU LY CHUOI =====\n");
    printf("1. Dem so luong khoang trang trong chuoi\n");
    printf("2. Loai bo tat ca khoang trang trong chuoi\n");
    printf("3. Noi hai chuoi s1 va s2\n");
    printf("4. Viet hoa ky tu dau moi tu\n");
    printf("5. Dao nguoc chuoi\n");
    printf("-1. Thoat chuong trinh\n");
    printf("=====================================\n");
    printf("Nhap lua chon cua ban: ");
}
void daoNguocChuoi(char str[]){
    int doDai=strlen(str);
    int i=0, j=doDai-1;
    while(i<j){
        int temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}
int main()
{
    char str[100];
    int choice;
    printf("Nhap chuoi:\n");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
      do {
        display();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: {
                int demKT = demKhoangTrang(str);
                printf("So luong khoang trang la: %d\n", demKT);
                break;
            }
            case 2: {
                loaiKhoangTrang(str);
                printf("Chuoi sau khi loai bo khoang trang: %s\n", str);
                break;
            }
            case 3: {
                char str2[MAX_SIZE];
                fgets(str2, 100, stdin);
                str[strcspn(str, "\n")] = '\0';
                noiHaiChuoi(str, str2);
                printf("Chuoi s1 sau khi noi la: %s\n", str);
                break;
            }
            case 4: {
            chuyenChuoiHoaTuDau(str);
            printf("Chuoi chuyen cac ki tu dau thanh tu hoa la: %s\n", str);
            break;
            }
            case 5: {
            daoNguocChuoi(str);
            printf("Chuoi dao nguoc la: %s\n", str);
            break
            }
            case -1:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai!\n");
        }
    } while (choice != -1);
    return 0;
}
