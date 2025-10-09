#include <iostream>
using namespace std;
#define MAX_SIZE 100
typedef struct{
    char maSV[20];
    char ten[20];
    int tuoi;
}sinhVien;
typedef struct{
    int top;
    sinhVien danhSachSV[MAX_SIZE];
}Stack;
    void khoiTao(Stack *s){
        s->top=-1;
    }
    bool isEmpty(Stack *s){
        return s->top==-1;
    }
    bool isFull(Stack *s){
        return s->top==MAX_SIZE-1;
    }
    void Push(Stack *s, sinhVien sv){
        if(isFull(s)){
            cout<<"Stack da day!";
            return;
        }
        s->top++;
        s->danhSachSV[s->top]= sv;
        cout<<"Da them 1 sv";
    }
    sinhVien Pop(Stack *s){
        if(isEmpty(s)){
            cout<<"Stack rong";
        }
        sinhVien motSV;
        motSV=s->danhSachSV[s->top];
        s->top--;
        return motSV;
    }
    sinhVien nhapMotSinhVien(){
    sinhVien sv;
    cout << "Nhap ma sinh vien: ";
        cin.getline(sv.maSV, 20);
    cout << "Nhap ho ten: ";
        cin.getline(sv.ten, 50);
    cout << "Nhap tuoi: ";
        cin >> sv.tuoi;
        cin.ignore();
    return sv;
    }
    void xuatSinhVien(sinhVien sv) {
    cout << "Ma SV: " << sv.maSV << ", Ho ten: " << sv.ten << ", Tuoi: " << sv.tuoi << endl;
}
int main()
{
    Stack s;
    khoiTao(&s);
    int n;
    cout<<"Nhap so luong sinh vien muon push vao stack:";
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
    cout<<"\nNhap sinh vien thu"<<i+1<<"\n";
        sinhVien sv=nhapMotSinhVien();
        Push(&s, sv);
    }
    cout<<"\nLay 1 sinh vien ra khoi stack!";
        sinhVien layRaSV=Pop(&s);
        xuatSinhVien(layRaSV);
    return 0;
}
