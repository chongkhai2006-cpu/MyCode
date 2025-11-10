#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CAPACITY_INIT 4

typedef struct{
int maHang;
char tenMatHang[50];
int soLuong;
float donGia;
int soLuongTon;
int thoiGianBaoHanh;
}ThongTinMatHang;
typedef struct{
int capacity;
int size;
ThongTinMatHang *data;
}Vector;
void vector_Init(Vector *v){
    v->data=(ThongTinMatHang*)malloc(MAX_CAPACITY_INIT*sizeof(ThongTinMatHang));
    if(v->data==NULL){
        exit(1);
    }
    v->capacity= MAX_CAPACITY_INIT;
    v->size=0;
}
void vector_Resize(Vector *v){
    v->capacity*=2;
    ThongTinMatHang *new_Data;
    new_Data=(ThongTinMatHang*)realloc(v->data, v->capacity*sizeof(ThongTinMatHang));
    if(new_Data==NULL){
        exit(1);
    }
    v->data=new_Data;
}
void vector_free(Vector* v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
void vector_Push_Back(Vector *v, ThongTinMatHang value){
    if(v->capacity==v->size){
            vector_Resize(v);
    }
    v->data[v->size]=value;
    v->size++;
}
void nhapThongTinMathang(ThongTinMatHang *mh){
    printf("Nhap ma hang:\n");
    scanf("%d", &mh->maHang);
    getchar();
    printf("Nhap ten mat hang:\n");
    fgets(mh->tenMatHang, 50, stdin);
    mh->tenMatHang[strcspn(mh->tenMatHang,"\n")]='\0';
    printf("Nhap so luong:\n");
    scanf("%d", &mh->soLuong);
    printf("Nhap don gia:");
    scanf("%f", &mh->donGia);
    printf("Nhap so luong ton kho:");
    scanf("%d", &mh->soLuongTon);
    printf("Nhap thoi gian bao hanh (thang):\n");
    scanf("%d", &mh->thoiGianBaoHanh);
    getchar();
}
void inMatHang(ThongTinMatHang mh){
    printf("-Ma Hang: %d\n -Ten mat hang:%s\n -So luong: %d\n -Don gia: %.2f\n -So luong ton: %d\n -Thoi gian bao hanh: %d\n",
           mh.maHang, mh.tenMatHang, mh.soLuong, mh.donGia, mh.soLuongTon, mh.thoiGianBaoHanh);
}
void themMatHang(Vector *v){
    ThongTinMatHang mh;
    nhapThongTinMathang(&mh);
    vector_Push_Back(v, mh);
    printf("Da them thong tin 1 mat hang\n");
}
int timSoLuongTonLonNhat(Vector *v){
    int chiSoMH=0;
    int slTon= v->data[0].soLuongTon;
    for(int i=1; i<v->size; i++){
        if(v->data[i].soLuongTon>slTon){
            slTon=v->data[i].soLuongTon;
            chiSoMH=i;
        }
    }
    return chiSoMH;
}
int timDonGiaLonNhat(Vector *v){
    int chiSoMH=0;
    float donGiaMax= v->data[0].donGia;
    for(int i=1; i<v->size; i++){
        if(v->data[i].donGia>donGiaMax){
            donGiaMax=v->data[i].donGia;
            chiSoMH=i;
        }
    }
    return chiSoMH;
}
void timMatHangTGBHLonHon12(Vector *v){
     int found = 0;
    printf("Mat hang co thoi gian bao hanh lon hon 12 thang:\n");
    for(int i = 0; i < v->size; i++) {
        if(v->data[i].thoiGianBaoHanh > 12) {
            inMatHang(v->data[i]);
            found = 1;
        }
    }
    if(!found) {
        printf("Khong co mat hang nao co thoi gian bao hanh lon hon 12 thang\n");
    }
}
void sapXepMatHangTangDanTheoSLTon(Vector *v){
    for(int i=0; i<v->size-1; i++){
        int imin=i;
        for(int j=i+1; j<v->size; j++){
            if(v->data[j].soLuongTon<v->data[i].soLuongTon){
                imin=j;
            }
        }
        ThongTinMatHang temp=v->data[i];
        v->data[i]=v->data[imin];
        v->data[imin]=temp;
    }
}
void displayMenu(){
    printf("==========================================\n");
    printf("1. Them mat hang\n");
    printf("2. Mat hang co so luong ton nhieu nhat\n");
    printf("3. Mat hang co don gia cao nhat\n");
    printf("4. Thoi gian bao hanh lon hon 12 thang\n");
    printf("5. Sap xep theo so luong tang dan theo so luong ton\n");
    printf("6. In toan bo danh sach\n");
    printf("-1. Thoat menu\n");
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
        switch(choice){
        case 1:{
        printf("Bat dau them mat hang:\n");
        themMatHang(&v);
        break;
        }
        case 2:{
        printf("Mat hang co so luong ton nhieu nhat la:\n");
        int chiSoTonMax=timSoLuongTonLonNhat(&v);
        inMatHang(v.data[chiSoTonMax]);
        break;
        }
        case 3:{
        printf("Mat hang co don gia lon nhat:\n");
        int chiSoMH=timDonGiaLonNhat(&v);
        printf("Mat hang co don gia lon nhat la:\n");
        inMatHang(v.data[chiSoMH]);
        break;
        }
        case 4:{
        timMatHangTGBHLonHon12(&v);
            break;
        }
        case 5:{
            printf("Danh sach sau khi sap xep la:\n");
            sapXepMatHangTangDanTheoSLTon(&v);
            for(int i=0; i<v.size; i++){
            inMatHang(v.data[i]);
            }
            break;
        }
        case 6:{
        for(int i=0; i<v.size; i++){
            inMatHang(v.data[i]);
            }
            break;
        }
        case -1:
            printf("Da thoat khoi menu!\n");
            break;
        default:
            printf("Lua chon sai!\n");
            break;
        }

    }while(choice!=-1);
    vector_free(&v);
    return 0;
}

