#include <bits/stdc++.h>
using namespace std;
int isStrongPassword(char *pw){
    int dodai=strlen(pw);
    if(dodai<8){
        return 0;
    }
    int chuhoa=false;
    int chuthuong=false;
    int chuso=false;
    for(int i=0; i<dodai; i++){
        if(isupper(pw[i])){
            chuhoa=true;
        }
        if(islower(pw[i])){
            chuthuong=true;
        }
        if(pw[i]>='0' && pw[i]<='9'){
            chuso=true;
        }
    }
    return (chuhoa && chuso && chuthuong);
}
int main(){
    char pw[50];
    cout<<"Nhap mat khau:";
    cin>>pw;
    if(isStrongPassword(pw)){
        cout<<"Mat khau manh!";
    } else {
    cout<<"Mat khau yeu!";
    }
    return 0;
}
