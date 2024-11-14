// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
int scores[101];
// 입력, 테스트 출력

void print();

void sol()
{
    int MAX = scores[n - 1];
    int down_num = 0;
    for (int i = n - 2; i >= 0; i--)
    { // 7 5  7-5+1 값만큼 내린다
        // cout << MAX << scores[i] << endl;
        if (MAX <= scores[i])
        {
            down_num += (scores[i] - MAX + 1);
            scores[i] = MAX - 1;
            MAX -= 1;
        }
        else
        {
            MAX = scores[i];
        }
        // cout << MAX << scores[i] << down_num << endl;
        // cout << "====" << endl;
    }
    cout << down_num << endl;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-2847_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
