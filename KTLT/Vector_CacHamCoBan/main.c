#include <stdio.h>
#include <stdlib.h>
#define Init_Capacity 4
typedef struct{
int *data;
int capacity;
int size;
}Vector;
void khoiTao(Vector *v){
    v->capacity=Init_Capacity;
    v->size=0;
    v->data=(int*)malloc(v->capacity*sizeof(int));
    if(v->data== NULL){
        exit(1);
    }
}
void vector_free(Vector *v){
    free(v->data);
    v->data=NULL;
    v->size=0;
    v->capacity=0;
}
void resizeVector(Vector *v){
v->capacity*=2;
int *newdata=(int*)realloc(v->data, v->capacity*sizeof(int));
if(newdata==NULL){
    exit(1);
}
v->data=newdata;
printf("Dung luong moi:%d\n", v->capacity);
}
void push_back(Vector *v, int value){
    if(v->size==v->capacity){
        resizeVector(v);
    }
    v->data[v->size]= value;
    v->size++;
    printf("Push:%d\n", value);
}
int get(Vector *v, int index){
    if(index>=0 && index<v->size){
            return v->data[index];
    }
    printf("Chi muc loi");
    exit(1);
}
void set(Vector *v, int index, int value){
    if(index>=0 && index<v->capacity){
        return v->data[index]=value;
    }
    printf("Loi!");
    return;
}
void pop_back(Vector *v){
        if(v->size>0){
            v->size--;
        }
}
void remove_at(Vector *v, int index){
    if(index<0 || index>=v->size){
        printf("Loi index\n");
        return;
    }
    if(index == v->size-1){
        pop_back(v);
        return;
    }
    memmove(&v->data[index], &v->data[index+1], (v->size-index-1)*sizeof(int));
    v->size--;
}
void v_print(Vector *v){
    printf("Vector (Size: %d, Capacity: %d)\n", v->size, v->capacity);
    printf("Data[");
    for(int i=0; i<v->size; i++){
        printf("%d \t", v->data[i]);
    }
    printf("]\n");
}
int vector_size(Vector* v) {
    return v->size;
}
int main()
{
    Vector v;
    khoiTao(&v);
    v_print(&v);
    push_back(&v, 10);
    push_back(&v, 20);
    push_back(&v, 30);
    push_back(&v, 40);
    push_back(&v, 50);
    v_print(&v);
    printf("Phan tu index 2 la: %d\n", get(&v,2));
    printf("Thay doi phan tu tai index 2 thanh 99\n");
    set(&v, 2, 99);
    v_print(&v);
    printf("Xoa gia tri cuoi!\n");
    pop_back(&v);
    v_print(&v);
    printf("Xoa tai gia tri index 1\n");
    remove_at(&v, 1);
    v_print(&v);
    printf("Giai phong\n");
    vector_free(&v);
    v_print(&v);
    return 0;
}
