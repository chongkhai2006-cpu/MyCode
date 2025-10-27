#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;
cout<<"Nhap n:";
cin>>n;
bool laSNT=true;
if(n<2){
    laSNT=false;
} else {
for(int i=2; i<=sqrt(n); i++){
    if(n%i==0){
        laSNT=false;
        break;
        }
    }
}
    if(laSNT){
        cout<<"La so nguyen to!";
    } else {
        cout<<"Khong phai la so nguyen to";
    }
    return 0;
}
