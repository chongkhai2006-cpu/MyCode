#include <iostream>
using namespace std;
int main(){
    float diem10,diem4;
    string diemchu;
    cout<<"Nhap diem mon hoc theo thang diem 10:";
    cin>>diem10;
    if(diem10>=9){
        diem4=4.0;
        diemchu="A+";
    }else if(diem10 >= 8.0){
        diem4 = 3.5;
        diemchu = "A";
    }else if (diem10 >= 7.0){
        diem4 = 3.0;
        diemchu = "B+";
    }else if (diem10 >= 6.0){
        diem4 = 2.5;
        diemchu = "B";
    }else if (diem10 >= 5.0){
        diem4 = 2.0;
        diemchu = "C";
    }else if (diem10 >= 4.0){
        diem4 = 1.5;
        diemchu = "D";
    }else{
        diem4 = 1.0;
        diemchu = "F";
    }
    cout << "Diem (thang 10): " << diem10 << "\n";
    cout << "Diem (thang 4): " << diem4 << "\n";
    cout << "Diem chu: " << diemchu << "\n";
    return 0;
}

