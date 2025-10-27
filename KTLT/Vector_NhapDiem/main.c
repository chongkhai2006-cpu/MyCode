#include <stdio.h>
#include <stdlib.h>
#define Init_Vector 4
typedef struct{
    double *data;
    int size;
    int capacity;
}Vector;
void init_Vector(Vector *v){
    v->size=0;
    v->capacity=Init_Vector;
    v->data=(double*)malloc(v->capacity*sizeof(double));
    if(v->data==NULL){
        exit(1);
    }
}
void free_vector(Vector *v){
    free(v->data);
    v->data=NULL;
    v->size=0;
    v->capacity=0;
}
void resize_vector(Vector *v){
        v->capacity*=2;
        double *new_data=(double*)realloc(v->data, v->capacity*sizeof(double));
    if(new_data==NULL){
        exit(1);
    }
    v->data= new_data;
}
void push_back_vector(Vector *v, double value){
    if(v->size==v->capacity){
        resize_vector(v);
    }
    v->data[v->size]= value;
    v->size++;
}
double vector_get(Vector *v, int index) {
    if (index < 0 || index >= v->size) {
        printf("Chi so ngoai pham vi!\n");
        return 0;
    }
    return v->data[index];
}
double diemTrungBinh(Vector *v){
    double dtb=0;
    for(int i=0; i<v->size; i++){
        dtb+=vector_get(v, i);
    }
    return dtb/v->size;
}
double diemMax(Vector *v){
    double dMax=vector_get(v, 0);
    for(int i=1; i<v->size; i++){
        if(vector_get(v, i)>dMax){
            dMax=vector_get(v, i);
        }
    }
    return dMax;
}
double diemMin(Vector *v){
    double dMin=vector_get(v, 0);
    for(int i=1; i<v->size; i++){
        if(vector_get(v, i)<dMin){
            dMin=vector_get(v, i);
        }
    }
    return dMin;
}
int main()
{
    Vector v;
    init_Vector(&v);
    printf("Nhap diem thi [0.0-10.0], ( nhap -1 de ket thuc!)\n");
    double diem;
    while(1){
        printf("Diem:\n");
        scanf("%lf",&diem);
        if(diem==-1){
            break;
        }
        if(diem<0 || diem>10){
            printf("Diem khong hop le!\n");
            continue;
        }
        push_back_vector(&v, diem);
    }
    printf("Tong so sinh vien:%d\n", v.size);
    printf("Diem trung binh:%.2f\n", diemTrungBinh(&v));
    printf("Diem cao nhat:%.2f\n", diemMax(&v));
    printf("Diem thap nhat:%.2f\n", diemMin(&v));
    free_vector(&v);
    return 0;
}
