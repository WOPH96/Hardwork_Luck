// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n;
int stairs[301] = {0};
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
    freopen("dynamic_programming-2579_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol();

    return 0;
}

void input()
{
    cin >> n;
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> stairs[i];
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << stairs[i] << endl;
    }
}
