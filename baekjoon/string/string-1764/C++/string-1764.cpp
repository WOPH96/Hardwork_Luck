// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 입력변수생성
int n, m;
map<string, int> dict;

// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

void sol()
{
    vector<string> person;
    int cnt = 0;
    for (auto &elem : dict)
    {
        if (elem.second == 2)
        {
            cnt++;
            person.push_back(elem.first);
        }
    }
    std::sort(person.begin(), person.end());
    cout << cnt << endl;
    for (auto &elem : person)
        cout << elem << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("string-1764_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void input()
{
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n + m; i++)
    {
        string str;
        getline(cin, str);

        if (dict[str] == 0)
        {
            dict[str]++;
        }
        else
        {
            dict[str]++;
        }
    }
}
void print()
{
    for (auto &elem : dict)
    {
        cout << elem.first << " " << elem.second << endl;
    }
}
