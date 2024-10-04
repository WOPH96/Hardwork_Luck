// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// 입력변수생성
int n;
set<string> temp;
vector<string> strs;
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

bool cmp(string &s1, string &s2)
{
    if (s1.length() == s2.length())
    {
        return s1 < s2;
    }

    else if (s1.length() < s2.length())
        return true;
    else
        return false;
}
void sol()
{
    std::sort(strs.begin(), strs.end(), &cmp);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("string-1181_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    print();

    return 0;
}

void input()
{
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        temp.insert(s);
    }
    for (auto &elem : temp)
    {
        strs.push_back(elem);
    }
}
void print()
{
    for (auto &str : strs)
    {
        cout << str << endl;
    }
}
