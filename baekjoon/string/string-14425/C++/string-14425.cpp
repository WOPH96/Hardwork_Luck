// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 입력변수생성
int n, m;
// 다른 변수 생성
map<string, int> dict;
// 입력, 테스트 출력

void print();

void sol()
{
    int cnt = 0;
    for (auto &elem : dict)
    {
        if (elem.second >= 2)
        {
            // cout << elem.second << endl;
            cnt += elem.second - 1;
            // cnt++;
        }
    }

    cout << cnt << endl;
}

void input()
{
    cin >> n >> m;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);

        dict[str]++;
    }

    for (int i = 0; i < m; i++)
    {
        string str;
        getline(cin, str);
        if (dict[str] >= 1)
            dict[str]++;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("string-14425_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void print()
{
    for (auto &elem : dict)
    {
        cout << elem.first << " " << elem.second << endl;
    }
}
