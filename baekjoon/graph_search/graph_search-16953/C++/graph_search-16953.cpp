// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// 입력변수생성
ll src, target;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void dfs(ll now, int try_num, bool &target_gottcha)
{
    // cout << now << " " << try_num << endl;
    if (now == target)
    {
        target_gottcha = true;
        cout << try_num << endl;
    }
    if (now > target)
    {
        // cout << -1 << endl;
        return;
    }
    dfs(now * 2, try_num + 1, target_gottcha);

    ll plusone = now * 10 + 1;

    dfs(plusone, try_num + 1, target_gottcha);
}

void sol()
{
    bool target_gottcha = false;
    dfs(src, 1, target_gottcha);
    if (!target_gottcha)
        cout << -1 << endl;
    // cout << nums_of_try << endl;
}

void input()
{
    cin >> src >> target;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-16953_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
