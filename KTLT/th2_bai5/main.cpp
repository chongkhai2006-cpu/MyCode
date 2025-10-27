#include <iostream>
using namespace std;
long long giaothuakep(int n){
    long long gt=1;
    int i=n;
    while(i>1){
        gt=gt*i;
        i=i-2;
    }
    return gt;
}
int main(){
 int n;
 cout<<"Nhap n:";
 cin>>n;
 cout<<n<<"!!="<<giaothuakep(n);
}
