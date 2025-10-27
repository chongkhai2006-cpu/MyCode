#include <iostream>
using namespace std;
int tinhsothang(double tienbandau, double tiencanco, double laisuat){
    int thang=0;
    while (tienbandau < tiencanco){
        tienbandau=tienbandau+(tienbandau*laisuat)/100;
        thang++;
    }
    return thang;
}
int main(){
double tienbandau, tiencanco, laisuat;
int thang;
cout<<"Nhap so tien ban dau:";
cin>>tienbandau;
cout<<"Nhap so tien can co:";
cin>>tiencanco;
cout<<"Lai suat:";
cin>>laisuat;
cout<<"Can co "<<tinhsothang(tienbandau,tiencanco,laisuat)<<" thang";
}
