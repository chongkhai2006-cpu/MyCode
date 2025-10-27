#include <iostream>
using namespace std;
double tinhtiennhan(double sotiengui, double laisuat, int thang){
    for(int i=1; i<=thang; i++){
        sotiengui=sotiengui+(sotiengui*laisuat)/100;
    }
    return sotiengui;
}
int main(){
    double sotiengui, laisuat;
    int thang;
    cout<<"Nhap so tien gui:";
    cin>>sotiengui;
    cout<<"Nhap so thang gui:";
    cin>>thang;
    cout<<"Lai suat:";
    cin>>laisuat;
    cout<<"So tien nhan duoc:"<<tinhtiennhan(sotiengui,laisuat,thang);
    return 0;
}
