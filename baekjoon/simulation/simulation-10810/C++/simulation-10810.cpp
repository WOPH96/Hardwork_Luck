// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, m;

// 다른 변수 생성
int bucket[101] = {0};
// 입력, 테스트 출력
void input();
void print();

void sol(int start, int end, int num)
{

    for (int i = start; i <= end; i++)
    {
        bucket[i] = num;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("simulation-10810_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol();

    return 0;
}

void input()
{
    cin >> n >> m;
    while (m)
    {
        int s, e, n;
        cin >> s >> e >> n;
        sol(s, e, n);
        m--;
    }
}
void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << bucket[i] << " ";
    }
    cout << endl;
}
