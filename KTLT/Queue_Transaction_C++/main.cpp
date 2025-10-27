#include <iostream>
using namespace std;
#define MAX_SIZE 5
typedef struct{
    char tenKH[50];
    int loaiGiaoDich; //1 Gửi tiền 2 Rút tiền 3 Chuyển khoảng
    double soTien;
}Transaction;
typedef struct{
Transaction ds[MAX_SIZE];
int Front;
int Rear;
int Count;
}CircularQueue;
void createQueue(CircularQueue *q){
    q->Front=0;
    q->Rear=-1;
    q->Count=0;
}
bool isFull(CircularQueue *q){
    return q->Count==MAX_SIZE;
}
bool isEmpty(CircularQueue *q){
    return q->Count==0;
}
void enqueue(CircularQueue *q, Transaction t){
    if(isFull(q)){
        cout<<"Queue da day!\n";
        return;
    }
    q->Rear=(q->Rear+1)%MAX_SIZE;
    q->ds[q->Rear]=t;
    q->Count++;
}
Transaction dequeue(CircularQueue *q){
    Transaction Empty = {"", 0, 0};
    if(isEmpty(q)){
        cout<<"Queue rong!\n";
        return Empty;
    }
    Transaction t=q->ds[q->Front];
    q->Front=(q->Front+1)%MAX_SIZE;
    q->Count--;
    return t;
}
void printTransaction(Transaction t){
    cout<<"----Dang xu li giao dich:---\n";
    cout<<"-Ten khach hang:"<<t.tenKH<<"\n";
    cout<<"-Loai giao dich:\n";
    switch(t.loaiGiaoDich){
    case 1:
    cout<<"-Gui tien\n";
    break;
    case 2:
    cout<<"-Rut tien\n";
    break;
    case 3:
    cout<<"-Chuyen khoan\n";
    break;
    default: cout<<"-Loi giao dich\n"; break;
    }
    cout<<"-So tien:"<<t.soTien<<"\n";
}
int main(){
    CircularQueue q;
    createQueue(&q);
    Transaction t1={"Vo Trong Khai", 1, 10000};
    Transaction t2={"Vo Chong Khai", 2, 20000};
    Transaction t3={"Vo Trong F ", 3, 30000};
    Transaction t4={"Vo Trong A", 1, 40000};
    Transaction t5={"Vo Trong B", 2, 50000};
    Transaction t6={"Vo Trong C", 3, 60000};
    Transaction t7={"Vo Trong D", 1, 100000};
    enqueue(&q, t1);
    enqueue(&q, t2);
    enqueue(&q, t3);
    enqueue(&q, t4);
    enqueue(&q, t5);
    enqueue(&q, t6);
    cout<<"---Bat dau xu ly giao dich!---\n";
    printTransaction(dequeue(&q));
    printTransaction(dequeue(&q));
    cout<<"----Them giao dich moi!----\n";
    enqueue(&q, t7);
    cout<<"---Xu li cac giao dich con lai\n";
    while(!isEmpty(&q)){
        printTransaction(dequeue(&q));
    }
    return 0;
}
