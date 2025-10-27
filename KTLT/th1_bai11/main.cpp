#include <iostream>
using namespace std;
int main()
{
int n;
cin>>n;
for(int i=n; i>=1; i++){
    int giatiensp, tienbovaomuasp, tienthua;
    cin>>giatiensp;
    cin>>tienbovaomuasp;
    tienthua = tienbovaomuasp - giatiensp;
    int to10;
    to10=tienthua/10;
    int du,to5,to1;
    du=tienthua%10;
    if(du>=5){
        to5=1;
        du-=5;
    }
    to1=du;
    cout<<tienthua <<" = "<< to10<<" * 10 + "<<to5<<" * 5 + "<<to1<<" * 1 ";
}
return 0;
}
