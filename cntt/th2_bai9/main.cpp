#include <bits/stdc++.h>
using namespace std;
void daoNguocChuoi(char *pw){
    int left=0;
    int right=strlen(pw)-1;
    while(left<right){
        char temp;
        temp=pw[left];
        pw[left]=pw[right];
        pw[right]=temp;
        left++;
        right--;
    }
}
int main()
{
char pw[]="Hellllllooooo";
daoNguocChuoi(pw);
cout<<"Chuoi dao nguoc la:"<<pw;
return 0;
}
