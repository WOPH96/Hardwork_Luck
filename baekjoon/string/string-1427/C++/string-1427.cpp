// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
string strs;
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

bool cmp(char &c1, char &c2)
{
    return c1 > c2;
}
void sol()
{
    std::sort(strs.begin(), strs.end(), greater<char>());
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("string-1427_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    print();

    return 0;
}

void input()
{
    cin >> strs;
}
void print()
{
    cout << strs << endl;
}
