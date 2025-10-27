#include <bits/stdc++.h>
using namespace std;
struct khachhang{
string tenkh;
int chisocu;
int chisomoi;
};
khachhang kh;
int main(){
    int soluong;
    double tiendien;
    cout<<"Ten Khach Hang:";
    getline(cin,kh.tenkh);
    cout<<"Chi so cu:";
    cin>>kh.chisocu;
    cout<<"Chi so moi:";
    cin>>kh.chisomoi;
    if(kh.chisomoi<kh.chisocu){
        cout<<"Nhap du lieu khong hop le!";
        return 0;
    }
    soluong=kh.chisomoi-kh.chisocu;
    if(soluong<=100){
        tiendien=soluong*1.418;
    } else if(soluong<=150){
        tiendien=100*1.418+(soluong-100)*1.622;
    } else if(soluong<=200){
        tiendien=100*1.418+50*1.622+(soluong-150)*2.044;
    } else if(soluong<=300){
        tiendien=100*1.418+50*1.622+50*2.044+(soluong-200)*2.210;
    }
      else if(soluong<=400){
        tiendien=100*1.418+50*1.622+50*2.044+100*2.210+(soluong-300)*2.361;
    } else {
        tiendien = 100 * 1.418 + 50 * 1.622 + 50*2.044 + 100*2.210 + 100* 2.361 + (soluong-400)*2.420;
    }
cout<<"Ten khach hang:"<<kh.tenkh<<"\n";
cout<<"So Kwh tieu thu:"<<soluong<<"\n";
cout<<"Thanh tien:"<<tiendien<<"VND\n";
return 0;
}
