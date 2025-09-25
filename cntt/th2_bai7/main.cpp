#include <bits/stdc++.h>
using namespace std;
bool kiemtrasont(int x){
    if (x<2){
        return 0;
    }
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int demsont(int n, int m){
    int dem=0;
    for (int i=n; i<=m;i++){
    if(kiemtrasont(i)){
        dem++;
        }
    }
    return dem;
}
int main(){
int n,m;
cout<<"So nguyen to trong doan 1 den 10 la:"<<demsont(1,10);
cout<<"\n";
cout<<"So nguyen to trong doan 1 den 1000 la:"<<demsont(1,1000);
cout<<"\n";
cout<<"So nguyen to trong doan 1001 den 100000 la:"<<demsont(1001,100000);
return 0;
}
