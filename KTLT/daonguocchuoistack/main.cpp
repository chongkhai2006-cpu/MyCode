#include <iostream>
#include <cstring>
using namespace std;
#define MAX_SIZE 100
typedef struct {
 int top;
 char arr[MAX_SIZE];
}Stack;
void khoiTao(Stack *s){
    s->top=-1;
}
bool isEmpty(Stack *s){
    return s->top==-1;
}
bool isFull(Stack *s){
    return s->top == MAX_SIZE -1;
}
void push(Stack *s, char c){
if(isFull(s)){
    cout << "Loi: Stack day (Overflow)!" << endl;
    return;
}
    s->top++;
    s->arr[s->top]=c;
}
char pop(Stack *s){
if(isEmpty(s)){
    cout << "Loi: Stack rong (Underflow)!" << endl;
    return '\0';
}
char chuoi;
chuoi=s->arr[s->top];
s->top--;
return chuoi;s
}
void daoNguocChuoi(char *str){
    Stack s;
    khoiTao(&s);
    int len=strlen(str);
    for(int i=0; i<len; i++){
            push(&s, str[i]);
}
    for(int i=0; i<len; i++){
        str[i]=pop(&s);
    }
}
int main()
{
   char chuoi[MAX_SIZE];
   cout<<"Nhap chuoi can dao nguoc:";
   cin.getline(chuoi, MAX_SIZE);
   cout<<"Chuoi ban dau: "<<chuoi<<"\n";
   daoNguocChuoi(chuoi);
   cout<<"Chuoi dao nguoc: "<<chuoi<<"\n";
   return 0;
}
