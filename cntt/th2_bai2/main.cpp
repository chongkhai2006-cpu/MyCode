#include <bits/stdc++.h>
using namespace std;
double dientich(double a, double b, double c){
    double p;
    p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
string phanloai(double a, double b, double c){
    if (a+b<=c || a+c<=b || b+c<=a){
        return "Khong phai la 1 tam giac";
    }
    if(a==b && b==c){
        return "La tam giac deu";
    }
    if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a ){
        if(a==b || b==c || a==c){
            return "La tam giac vuong can";
        } else {
       return "La tam giac vuong";
        }
    }
    if(a==b || b==c || a==c){
        return "La tam giac can";
    } else {
    return "La tam giac thuong";
    }
}
int main()
{
    double a,b,c;
    cout<<"Nhap 3 canh cua tam giac:";
    cin>>a>>b>>c;
    string loai;
    loai = phanloai(a,b,c);
    double dt=dientich(a,b,c);
    cout<<"Day "<<loai;
    cout<<"\n";
    if(loai!="Khong phai la 1 tam giac"){
        cout<<"Dien tich la:"<<dt;
    }
    return 0;
}
