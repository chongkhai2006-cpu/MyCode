#include <stdio.h>
#include <stdlib.h>
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
void push_Stack(Stack *s, char value){
    if(isFull(s)){
        printf("Stack da day!");
        return;
    }
    s->top++;
    s->data[s->top]=value;
}
char pop_Stack(Stack *s){
    if(isEmpty(s)){
        printf("Stack rong!");
        return '\0';
    }
    char value;
    value=s->data[s->top];
    s->top--;
    return value;
}
void daoNguocChuoi(char *myString){
    int len=strlen(myString);
    Stack s;
    init_Stack(&s);
    for(int i=0; i<len; i++){
        push_Stack(&s, myString[i]);
    }
    for(int j=0; j<len; j++){
        myString[j]=pop_Stack(&s);
    }
}
int main(){
    char myString[MAX_SIZE];
    printf("Nhap chuoi can dao nguoc:\n");
    fgets(myString, sizeof(myString), stdin);
    printf("Chuoi hien tai:%s\n", myString);
    daoNguocChuoi(myString);
    printf("Chuoi dao nguoc:%s\n", myString);
    return 0;
}
