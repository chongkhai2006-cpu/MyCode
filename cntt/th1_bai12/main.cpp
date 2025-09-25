#include <bits/stdc++.h>
using namespace std;
int t;
int a[8];
int s[7];
int sum = 0, x;
bool ch;
int u, v, w;

void si(int k, int n)
{
    for(int i = 0; i <= 9; i ++)
    {
        s[k] = i;
        sum += i;
        if(k == n)
        {
           ch = 1;
           for(int j = 1; j <= 3; j ++)
           {
               if(s[j] != s[6 - j + 1])
               {
                   ch = 0;
                   break;
               }
           }
           if(ch)
           {
               a[3] ++;
               x = sum;
               if(x % 10 == 0)
               {
                   a[2] ++;
                   ch = 1;
                   for(int j = 1; j <= 6; j ++)
                   {
                       if(s[j] == 0)
                       {
                           ch = 0;
                           break;
                       }
                   }
                   if(ch) a[1] ++;
               }
           }
        }
        else si(k + 1, n);
        sum -= i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Lamle.INP","r", stdin);
    //freopen("Lamle.OUT","w", stdout);
    memset(a, 0, sizeof a);
    si(1, 6);
    //cout << a[1] << " " << a[2] << " " << a[3] << '\n';
    cin >> t;
    while(t --)
    {
        cin >> u >> v >> w;
        if(u > a[1])
        {
            cout << "NO" << '\n';
            continue;
        }
        if(a[2] - a[1] < v)
        {
            cout << "NO" << '\n';
            continue;
        }
        if(a[3] - a[2] - a[1] < w)
        {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
    }
}
