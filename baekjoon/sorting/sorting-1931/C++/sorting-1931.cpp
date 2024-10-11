// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
struct Time
{
    int start, end;
    Time(int s, int e) : start(s), end(e) {}
    friend ostream &operator<<(ostream &out, Time &t)
    {
        out << t.start << " " << t.end;
        return out;
    }
};
struct cmp
{
    bool operator()(Time &t1, Time &t2)
    {
        if (t1.end == t2.end)
        {
            return t1.start < t2.start;
        }
        return t1.end < t2.end;
    }
};
// 입력, 테스트 출력
vector<Time> time_table;
void print();

void sol()
{
    sort(time_table.begin(), time_table.end(), cmp());
    int now_end = 0;
    int cnt = 0;
    for (auto &time : time_table)
    {
        if (time.start >= now_end)
        {
            cnt++;
            now_end = time.end;
        }
    }
    cout << cnt << "\n";
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int st, et;
        cin >> st >> et;
        time_table.emplace_back(st, et);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("sorting-1931_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();

    sol();
    // print();

    return 0;
}

void print()
{
    for (auto &time : time_table)
    {
        cout << time << "\n";
    }
}
