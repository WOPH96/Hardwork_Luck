// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n;
// vector<int> num_list;
priority_queue<int, vector<int>, greater<int>> num_list;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    while (!num_list.empty())
    {
        cout << num_list.top() << "\n";
        num_list.pop();
    }
}

void input()
{
    cin >> n;
    while (n)
    {
        int num;
        cin >> num;
        num_list.push(num);
        n--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("sorting-2751_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}

void print()
{
}
