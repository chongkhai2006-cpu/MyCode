#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_VECTOR 4
typedef struct{
int maSach;
char tenSach[50];
char tenTacGia[50];
int soLuong;
}ThongTinSach;
typedef struct{
ThongTinSach *data;
int size;
int capacity;
}Vector;
void vector_Init(Vector *v){
    v->capacity=SIZE_VECTOR;
    v->size=0;
    v->data=(ThongTinSach*)malloc(SIZE_VECTOR*sizeof(ThongTinSach));
    if(v->data==NULL){
        exit(1);
    }
}
void vector_Free(Vector *v){
    free(v->data);
    v->data=NULL;
    v->capacity=0;
    v->size=0;
}
void resize_Vector(Vector *v){
    v->capacity*=2;
    if(v->capacity>100){
        v->capacity=100;
    }
    ThongTinSach *new_Data=(ThongTinSach*)realloc(v->data, v->capacity*sizeof(ThongTinSach));
    if(new_Data==NULL){
        exit(1);
    }
    v->data=new_Data;
}
void vector_Push_Back(Vector *v, ThongTinSach value){
    if(v->capacity>100){
        printf("Danh sach toi da 100 dau sach! Khong the them nua!\n");
        return;
    }
    if(v->capacity==v->size){
        resize_Vector(v);
    }
    v->data[v->size]=value;
    v->size++;
}
void nhapThongTinCuonSach(Vector *v){
    ThongTinSach sach;
    printf("Nhap ma sach:\n");
    scanf("%d", &sach.maSach);
    getchar();
    printf("Nhap ten sach:\n");
    fgets(sach.tenSach, 50, stdin);
    sach.tenSach[strcspn(sach.tenSach, "\n")]='\0';
    printf("Nhap ten tac gia:\n");
    fgets(sach.tenTacGia, 50, stdin);
    sach.tenTacGia[strcspn(sach.tenTacGia, "\n")]='\0';
    printf("Nhap so luong sach:\n");
    scanf("%d", &sach.soLuong);
    getchar();
    vector_Push_Back(v, sach);
    printf("Da them thong tin cuon sach\n");
}
void hienThiThongTin1CuonSach(ThongTinSach sach){
    printf("-Ma sach: %d\n -Ten sach: %s\n -Ten tac gia: %s\n -So luong: %d\n", sach.maSach, sach.tenSach, sach.tenTacGia, sach.soLuong);
}
void timSachTheoTen(Vector *v, char tenSach[]){
    int found=0;
    for(int i=0; i<v->size; i++){
        if(strcmp(tenSach, v->data[i].tenSach)==0){
            hienThiThongTin1CuonSach(v->data[i]);
            found =1;
        }
    }
    if(found==0){
        printf("Khong tim thay!\n");
    }
}
void timSachTheoTenTacGia(Vector *v, char tenTacGia[]){
    int found =0;
    for(int i=0; i<v->size; i++){
        if(strcmp(tenTacGia, v->data[i].tenTacGia)==0){
            hienThiThongTin1CuonSach(v->data[i]);
            found =1;
        }
    }
    if(found==0){
        printf("Khong tim thay!\n");
    }
}
int tinhTongSoSach(Vector *v){
    int tongSach=0;
    for(int i=0; i<v->size; i++){
        tongSach+=v->data[i].soLuong;
    }
    return tongSach;
}
void displayMenu(){
    printf("1. Nhap thong tin sach\n");
    printf("2. Tim theo ten quyen sach\n");
    printf("3. Tim sach theo ten tac gia\n");
    printf("4. Tong so sach hien co\n");
    printf("5. In danh sach\n");
    printf("-1. Thoat khoi menu!\n");
}
int main()
{
    Vector v;
    vector_Init(&v);
    int choice;
    do{
        displayMenu();
        printf("Nhap lua chon:\n");
        scanf("%d", &choice);
        getchar();
    switch(choice){
    case 1:{
    printf("Bat dau nhap thong tin sach:\n");
    nhapThongTinCuonSach(&v);
    break;
    }
    case 2:{
    char tenSach[50];
    printf("Nhap ten sach can tim:\n");
    fgets(tenSach, 50, stdin);
    tenSach[strcspn(tenSach, "\n")]='\0';
    timSachTheoTen(&v, tenSach);
    break;
    }
    case 3:{
    char tenTacGia[50];
    printf("Nhap ten tac gia cua cuon sach can tim:\n");
    fgets(tenTacGia, 50, stdin);
    tenTacGia[strcspn(tenTacGia, "\n")]='\0';
    timSachTheoTenTacGia(&v, tenTacGia);
    break;
    }
    case 4:
    printf("Tong so sach hien tai la: %d\n", tinhTongSoSach(&v));
    break;
    case 5:{
    printf("===========Danh sach===========\n");
    for(int i=0; i<v.size; i++){
            hienThiThongTin1CuonSach(v.data[i]);
        }
    printf("===============================\n");
    break;
    }
    case -1:
    printf("Da thoat khoi menu!");
    break;
    default:
    printf("Nhap sai lua chon!\n");
    break;
    }
    }while(choice!=-1);
    vector_Free(&v);
}
