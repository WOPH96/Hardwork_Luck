// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, m;
// 입력변수생성
int combination[10] = {0};
int is_used[10] = {0};
// 입력, 테스트 출력
void input();
void print();

void sol(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << combination[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (is_used[i] == 0)
        {
            combination[idx] = i;
            is_used[i] = 1;
            sol(idx + 1);
            is_used[i] = 0;
        }
    }
}
/*
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("back_tracking-15649_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol(0);

    return 0;
}

void input()
{
    cin >> n >> m;
}
void print() {}
