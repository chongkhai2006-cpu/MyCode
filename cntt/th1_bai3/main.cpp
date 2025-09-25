#include <iostream>
using namespace std;
int main(){
int thang,nam,songay;
cout<<"Nhap thang:";
cin>>thang;
cout<<"\n";
cout<<"Nhap nam:";
cin>>nam;
cout<<"\n";
if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12){
        songay = 31;
    }
    else if(thang == 4 || thang == 6 || thang == 9 || thang == 11){
        songay = 30;
    }
    else if (thang==2){
    if((nam%4==0 && nam%100!=0)||(nam%400==0)){
       songay=29;
       } else{
       songay=28;
       }
    }else{
    songay=0;
    }
     cout << "So ngay cua thang " << thang << " nam " << nam << " la: " << songay << endl;
}
