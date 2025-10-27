#include <stdio.h>
#include <stdlib.h>
#define MAX_CUSTOMER 3
typedef struct{
    int ds[MAX_CUSTOMER];
    int rear;
    int front;
    int count;
}CustomerQueue;
void init_CustomerQueue(CustomerQueue *q){
    q->rear=-1;
    q->front=0;
    q->count=0;
}
int isFULL(CustomerQueue *q){
    return q->count==MAX_CUSTOMER;
}
int isEmpty(CustomerQueue *q){
    return q->count==0;
}
void enQueue(CustomerQueue *q,int value){
    if(isFULL(q)){
        printf("Hang doi da day!\n");
        return;
    }
    q->rear=(q->rear +1)% MAX_CUSTOMER;
    q->ds[q->rear]=value;
    q->count++;
    printf("Khach hang ID: %d da vao hang doi!\n", value);
}
char dequeue(CustomerQueue *q){
    if(isEmpty(q)){
        printf("Hang doi trong!\n");
        return;
    }
    char value;
    value=q->ds[q->front];
    q->front=(q->front+1)%MAX_CUSTOMER;
    q->count--;
    return value;
}
int main()
{
    CustomerQueue q;
    init_CustomerQueue(&q);
    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);
    printf("Phuc vu cac khach hang:\n");
    printf("ID:%d\n", dequeue(&q));
    printf("ID:%d\n", dequeue(&q));
    printf("ID:%d\n", dequeue(&q));
    return 0;

}
