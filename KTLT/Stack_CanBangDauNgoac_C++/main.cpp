#include <iostream>
#include <cstring>
using namespace std;
#define MAX_SIZE 100
typedef struct{
int top;
char ds[MAX_SIZE];
}Stack;
void khoiTao(Stack *s){
s->top=-1;
}
bool isFull(Stack *s){
    return s->top==MAX_SIZE-1;
}
bool isEmpTy(Stack *s){
    return s->top==-1;
}
void Push(Stack *s, char c){
    if(isFull(s)){
        return;
    }
    s->top++;
    s->ds[s->top]=c;
}
char Pop(Stack *s){
    char ngoac;
    ngoac=s->ds[s->top];
    s->top--;
    return ngoac;
}
bool checkBalance(char *chuoi){
    Stack s;
    khoiTao(&s);
    for(int i=0; chuoi[i]!='0'; i++){
        char c=chuoi[i];
        if(c=='(' || c=='{' || c=='['){
            Push(&s,c);
        }
        else if( c==')' || c=='}' || c==']'){
            if(isEmpTy(&s)) return false;
            char top=Pop(&s);
            if((c==')' && top!='(') || (c==']' && top!='[') || (c=='}' && top!='{')){
                return false;
            }
        }
    }
    return isEmpTy(&s);
}
int main()
{
    char chuoi[MAX_SIZE];
    cin.getline(chuoi,MAX_SIZE);
    if(checkBalance(chuoi)){
       cout<<"Hop le!";
       } else {
       cout<<"Khong hop le!";
       }
       return 0;
}
