#include <iostream>
using namespace std;
int main()
{
int n;
cout<<"Nhap n:";
cin>>n;
long long gt=1;
int i=n;
while(i>1){
    gt=gt*i;
    i=i-2;
    }
    cout<<n<<"!!="<< gt;
}
