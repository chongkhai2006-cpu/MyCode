#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct{
    char customerName[50];
    int typeTransaction; //1. gui tien, 2. rut tien, 3. chuyen tien
    double amount;
}Transaction;
typedef struct{
    Transaction data[MAX_SIZE];
    int front;
    int rear;
    int count;
}CircularQueue;
void init_Queue(CircularQueue *q){
    q->front=0;
    q->rear=-1;
    q->count=0;
}
int isFull(CircularQueue *q){
    return q->count==MAX_SIZE;
}
int isEmpty(CircularQueue *q){
    return q->count==0;
}
void enQueue(CircularQueue *q, Transaction newTransaction){
    if(isFull(q)){
        printf("Hang doi da day!\n");
        return;
    }
    q->rear=(q->rear+1)%MAX_SIZE;
    q->data[q->rear]=newTransaction;
    q->count++;
}
Transaction deQueue(CircularQueue *q){
    if(isEmpty(q)){
      Transaction  emptyError={"Error", 0, 0};
        printf("Hang doi rong!\n");
        return emptyError;
    }
    Transaction t= q->data[q->front];
    q->front=(q->front+1)%MAX_SIZE;
    q->count--;
    return t;
}
void printfTransaction(Transaction t){
    if(strcmp(t.customerName,"Error")!=0){
        printf("---Xu li giao dich---\n");
        printf("Ten khach hang: %s\n", t.customerName);
        switch(t.typeTransaction){
        case 1: printf("-Gui tien\n"); break;
        case 2: printf("-Rut tien\n"); break;
        case 3: printf("-Chuyen tien\n"); break;
        default: printf("Loi khong xac dinh!\n"); break;
        }
        printf("So tien:%.2f VND\n", t.amount);
        printf("-----------------------------\n");
    }
}
int main()
{
CircularQueue q;
init_Queue(&q);
Transaction t1={"Vo Trong Khai", 1, 10000};
    Transaction t2={"Vo Chong Khai", 2, 20000};
    Transaction t3={"Vo Trong F ", 3, 30000};
    Transaction t4={"Vo Trong A", 1, 40000};
    Transaction t5={"Vo Trong B", 2, 50000};
    Transaction t6={"Vo Trong C", 3, 60000};
    Transaction t7={"Vo Trong D", 1, 100000};
    enQueue(&q, t1);
    enQueue(&q, t2);
    enQueue(&q, t3);
    enQueue(&q, t4);
    enQueue(&q, t5);
    enQueue(&q, t6);
    printf("---Bat dau xu ly giao dich!---\n");
    printfTransaction(deQueue(&q));
    printfTransaction(deQueue(&q));
    printf("----Them giao dich moi!----\n");
    enQueue(&q, t7);
    printf("---Xu li cac giao dich con lai\n");
    while(!isEmpty(&q)){
        printfTransaction(deQueue(&q));
    }
    return 0;
}
