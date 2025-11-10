#include <bits/stdc++.h>
using namespace std;
int main()
{
double tiencanco, laisuat, tiengui;
int thang;
cout<<"Nhap tien can co:";
cin>>tiencanco;
cout<<"Nhap lai suat:";
cin>>laisuat;
cout<<"So thang can gui:";
cin>>thang;
tiengui=tiencanco/pow(1+laisuat,thang);
cout << "So tien it nhat phai gui ban dau la: " << tiengui;
return 0;
}
