#include <iostream>
using namespace std;
int main()
{
double tienGui, laiSuat;
int thang;
cout<<"Nhap so tien gui:";
cin>>tienGui;
cout<<"Nhap lai suat:";
cin>>laiSuat;
cout<<"So thang gui tien:";
cin>>thang;
int i=1;
while(i<=thang){
    tienGui=tienGui+(tienGui*laiSuat)/100;
    i++;
}
cout<<"So tien sau khi gui"<< thang <<"thang la:"<<tienGui;
}
