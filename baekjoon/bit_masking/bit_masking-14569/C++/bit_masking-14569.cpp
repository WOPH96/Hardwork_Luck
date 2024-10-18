// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, m;
int k[1001] = {0};
int classes[1001][51] = {0};
int classes_std[10001][51] = {0};
// 다른 변수 생성

// 입력, 테스트 출력

void print();
int check(int *student)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int correct = 0;
        for (int j = 1; j <= 50; j++)
        {
            if (classes[i][j] && student[j])
                correct++;
            if (correct == k[i])
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}
void sol()
{
    // 수업 1 & 학생시간 1이어야 할때
    for (int i = 0; i < m; i++)
    {
        cout << check(classes_std[i]) << "\n";
    }
}

void input()
{
    int p;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];

        for (int j = 0; j < k[i]; j++)
        {
            int time;
            cin >> time;
            classes[i][time] = 1;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            int time;
            cin >> time;
            classes_std[i][time] = 1;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("bit_masking-14569_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (auto &c : classes[i])
        {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (auto &c : classes_std[i])
        {
            cout << c << " ";
        }
        cout << endl;
    }
}
