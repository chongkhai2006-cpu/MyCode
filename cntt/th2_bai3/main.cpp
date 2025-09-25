#include <bits/stdc++.h>
using namespace std;
float tinhtiendien(float chisomoi, float chisocu){
    float soluong, tiendien;
    soluong=chisomoi-chisocu;
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
    return tiendien;
}
int main(){
    int n=10;
    for(int i=0;i<n;i++){
    float chisomoi, chisocu;
    cout<<"Nhap chi so moi:";
    cin>>chisomoi;
    cout<<"Nhap chi so cu:";
    cin>>chisocu;
    cout<<"Tien dien la:"<<tinhtiendien(chisomoi,chisocu)<<"VND";
    }
}
