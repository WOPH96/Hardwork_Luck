// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
priority_queue<int> positive_pq;
priority_queue<int, vector<int>, greater<int>> negative_pq;
// 입력, 테스트 출력

void print();

void sol()
{
    int sum = 0;
    while (!positive_pq.empty())
    {
        int max1 = positive_pq.top();
        positive_pq.pop();
        // 수가 하나밖에 안남았을 때
        if (positive_pq.empty())
        {
            sum += max1;
        }
        else
        {
            // 남은 수가 2보다 작을때
            // 2,1 이나오면 2*1보다 2+1이 큼
            if (max1 < 2 || positive_pq.top() < 2)
            {
                sum += max1;
            }
            else
            {
                int max2 = positive_pq.top();
                positive_pq.pop();
                sum += max1 * max2;
            }
        }
    }
    // 최대한 묶어
    while (!negative_pq.empty())
    {
        int max1 = negative_pq.top(); // 곱하면 최댓값이 되므로 걍 max
        negative_pq.pop();
        if (negative_pq.empty())
        {
            sum += max1;
        }
        else
        {
            // 최대한 묶어
            int max2 = negative_pq.top();
            negative_pq.pop();
            sum += max1 * max2;
        }
    }
    cout << sum << endl;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        if (data < 1)
        {
            negative_pq.push(data);
        }
        else
        {
            positive_pq.push(data);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-1744_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    while (!positive_pq.empty())
    {
        cout << positive_pq.top() << endl;
        positive_pq.pop();
    }
    while (!negative_pq.empty())
    {
        cout << negative_pq.top() << endl;
        negative_pq.pop();
    }
}
