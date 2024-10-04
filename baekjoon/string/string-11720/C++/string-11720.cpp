// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n;
string str;
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

void sol()
{
    int sum = 0;
    for (auto &elem : str)
    {
        sum += elem - '0';
        cout << sum << " ";
    }
    cout << str << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("string-11720_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}

void input()
{
    cin >> n;
    cin.ignore();
    getline(cin, str);
}
void print() {}
