#include <iostream>
using namespace std;
typedef struct {
    char msv[20];
    char hoten[30];
    int tuoi;
    float dtb;
} SinhVien;

SinhVien nhapMotSV(int i) {
    SinhVien sv;
    cout <<"NHAP THONG TIN SINH VIEN THU " << i + 1 << "\n";
    cout <<"Ma sinh vien:";
    cin >> sv.msv;
    cin.ignore();
    cout <<"Ho va ten:";
    cin.getline(sv.hoten, 30);
    cout <<"Tuoi: ";
    cin >> sv.tuoi;
    cout <<"Diem trung binh:";
    cin >> sv.dtb;
    return sv;
}
void nhapDanhSachSV(SinhVien *ds, int n) {
    cout << "\n===NHAP DANH SACH SINH VIEN===\n";
    for (int i = 0; i < n; i++) {
        ds[i] = nhapMotSV(i);
    }
}
void xuatMotSV(SinhVien sv, int i) {
    cout << "\n--- SINH VIEN THU " << i + 1 << " ---\n";
    cout << "Ma sinh vien: " << sv.msv << "\n";
    cout << "Ho va ten: " << sv.hoten << "\n";
    cout << "Tuoi: " << sv.tuoi << "\n";
    cout << "Diem trung binh: " << sv.dtb << "\n";
}
void xuatDanhSach(SinhVien ds[], int n) {
    cout << "\n=============================\n";
    cout << "   DANH SACH SINH VIEN VUA NHAP\n";
    for (int i = 0; i < n; i++) {
        xuatMotSV(ds[i], i);
    }
}
SinhVien timSVDMax(SinhVien ds[], int n) {
    int imax = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].dtb > ds[imax].dtb) {
            imax = i;
        }
    }
    return ds[imax];
}
void sapXepDiemTBGiamDan(SinhVien *ds, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(ds[i].dtb<ds[j].dtb){
                SinhVien temp=ds[i];
                ds[i]=ds[j];
                ds[j]=temp;
            }
        }
    }
}
int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    SinhVien ds[100];
    nhapDanhSachSV(ds, n);
    xuatDanhSach(ds, n);
    SinhVien svMax = timSVDMax(ds, n);
    cout << "\n=============================\n";
    cout << " SINH VIEN CO DIEM TB CAO NHAT\n";
    cout << "===============================\n";
    cout << "Ma sinh vien: " << svMax.msv << "\n";
    cout << "Ho va ten: " << svMax.hoten << "\n";
    cout << "Tuoi: " << svMax.tuoi << "\n";
    cout << "Diem trung binh: " << svMax.dtb << "\n";
    sapXepDiemTBGiamDan(ds, n);
    cout<<"Danh sach sinh vien co diem trung binh giam dan:";
    xuatDanhSach(ds,n);
    return 0;
}
