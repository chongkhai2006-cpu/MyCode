#include <bits/stdc++.h>
using namespace std;
bool kiemtraloai3(string so) {
    for (int i = 0; i < 3; i++) {
        if (so[i] != so[5 - i]) {
            return false;
        }
    }
    return true;
}
bool kiemtraloai2(string so) {
    int tong = 0;
    for (int i = 0; i < 6; i++) {
        tong += (so[i] - '0');
    }
    return (tong % 10 == 0);
}
bool kiemtraloai1(string so) {
    for (int i = 0; i < 6; i++) {
        if (so[i] == '0') {
            return false;
        }
    }
    return true;
}
int main() {
    int demloai1 = 0, demloai2 = 0, demloai3 = 0;
    for (long long i = 000000; i <= 999999; i++) {
        string so = to_string(i);
        while (so.length() < 6) {
            so = "0" + so;
        }
        if (kiemtraloai3(so)) {
            demloai3++;
            if (kiemtraloai2(so)) {
                demloai2++;
                if (kiemtraloai1(so)) {
                    demloai1++;
                }
            }
        }
    }
    cout<<demloai1<<"\n"<<demloai2<<"\n"<<demloai3<<"\n";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int N, M, K;
        cin >> N >> M >> K;
        if (N > demloai1) {
            cout << "NO\n";
            continue;
        }
        int loai2_con_lai = demloai2 - N;
        if (M > loai2_con_lai) {
            cout << "NO\n";
            continue;
        }
        int loai3_con_lai = demloai3 - (N + M);
        if (K > loai3_con_lai) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}
