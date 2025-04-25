#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) cin >> r[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    // Please write your code here.
    while(t--)
    {
        int r_temp = r[n-1];
        int d_temp = d[n-1];
        int l_temp = l[n-1];
        for(int i = n-1 ;i >0; i--)
        {
            r[i] = r[i-1];
            d[i] = d[i-1];
            l[i] = l[i-1];
        }
        l[0] = d_temp;
        r[0] = l_temp;
        d[0] = r_temp;
    }

    for (int i = 0; i < n; i++) cout << l[i] <<" ";
    cout<<"\n";
    for (int i = 0; i < n; i++) cout << r[i] <<" ";
    cout<<"\n";
    for (int i = 0; i < n; i++) cout << d[i] <<" ";
    return 0;
    return 0;
}
