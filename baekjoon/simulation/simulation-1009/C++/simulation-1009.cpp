// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 입력변수생성
int t;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol(int a, int b){
    int cnt = 0;
    int res = a%10;
    for(int i=1;i<b;i++){
        cnt++;
        res = (res*a)%10;
        // if(res==a) 
        //     break;
        
    }
    if(res==0)
        cout << 10 << endl;
    else
        cout << res << endl;
    // cout << "cnt =" << cnt << endl;
}

void input() {
    cin >> t;
    while(t){
        int a,b;
        cin >> a >> b;
        sol(a,b);
        t--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("simulation-1009_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    print();

    return 0;
}


void print() {

} 
