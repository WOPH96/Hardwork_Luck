// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
string s1, s2;
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

// void sol(){
// }

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("string-9251_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol();

    return 0;
}

void input()
{
    cin >> s1 >> s2;
}
void print()
{
    cout << s1 << endl;
    cout << s2 << endl;
}