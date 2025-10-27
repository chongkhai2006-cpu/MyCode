#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
typedef struct{
    char data[MAX_SIZE];
    int top;
}Stack;
void init_Stack(Stack *s){
    s->top=-1;
}
int isFull(Stack *s){
    return s->top==MAX_SIZE-1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}
void push_s(Stack *s, char value){
    if(isFull(s)){
        printf("Stack da day!\n");
        return;
    }
    s->top++;
    s->data[s->top]=value;
}
char pop_s(Stack *s){
    if(isEmpty(s)){
        printf("Mang rong!\n");
        return '\0';
    }
    char value;
    value=s->data[s->top];
    s->top--;
    return value;
}
int kiemTraBieuThuc(Stack *s, char *str){
    int len=strlen(str);
    for(int i=0; i<len; i++){
    if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
        push_s(s, str[i]);
        }
    else if (str[i]==')' || str[i]==']' || str[i]=='}'){
      if(isEmpty(s)){
        return 0;
      }
      char topChar=s->data[s->top];
     if(topChar == '(' && str[i]==')'||
        topChar == '[' && str[i]==']'||
        topChar == '{' && str[i]=='}'){
            pop_s(s);
        } else {
            return 0;
        }
      }
    }
    if(isEmpty(s)){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    Stack s;
    init_Stack(&s);
    char str[MAX_SIZE];
    printf("Nhap 1 bieu thuc chua cac dau ngoac!\n");
    fgets(str, sizeof(str), stdin);
    if(kiemTraBieuThuc(&s, str)){
        printf("Bieu thuc chua dau ngoac duoc dat dung!");
    } else {
        printf("Bieu thuc chua dau ngoac khong duoc dat dung!");
    }
      return 0;
}a
