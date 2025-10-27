#include <stdio.h>
#include <stdlib.h>
#define SIZE_VECTOR 4
typedef struct{
    int *data;
    int size;
    int capacity;
}Vector;
void init_Vector(Vector *v){
    v->size=0;
    v->capacity=SIZE_VECTOR;
    v->data=(int*)malloc(v->capacity*sizeof(int));
    if(v->data==NULL){
        printf("Cap phat loi!");
        exit(1);
    }
}
void free_vector(Vector *v){
    free(v->data);
    v->data=NULL;
    v->size=0;
    v->capacity=0;
}
void resizeVector(Vector *v){
     v->capacity*=2;
     int *new_data=(int*)realloc(v->data, v->capacity*sizeof(int));
     if(new_data==NULL){
        printf("Cap phat loi!");
        exit (1);
     }
     v->data=new_data;
}
void push_back(Vector *v, int value){
    if(v->size==v->capacity){
        resizeVector(v);
    }
    v->data[v->size]=value;
    v->size++;
}
int vector_get(Vector *v, int index){
    if(index <0 || index >= v->size){
        printf("Nhap index sai!");
        exit(1);
    }
    return v->data[index];
}
int main(){
    Vector v_all, v_even;
    init_Vector(&v_all);
    init_Vector(&v_even);
    int input;
    printf("Nhap 1 danh sach cac so nguyen, (-1 de ket thuc):\n");
    while(1){
        printf("Nhap gia tri:\n");
        scanf("%d", &input);
        if(input == -1){
            break;
        }
        push_back(&v_all, input);
    }
    for(int i=0; i<v_all.size; i++){
        int value=vector_get(&v_all, i);
    if(value%2==0){
        push_back(&v_even, value);
    }
}
    printf("Cac phan tu cua vector_all:\n");
    printf("[");
    for(int i=0; i<v_all.size; i++){
        printf("%d\t", vector_get(&v_all, i));
    }
    printf("]");
    printf("\nCac phan tu cua vector_even (so chan):\n");
    printf("[");
    for(int i=0; i<v_even.size; i++){
        printf("%d\t", vector_get(&v_even, i));
    }
    printf("]");
    free_vector(&v_all);
    free_vector(&v_even);
    return 0;
}
