// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int t;
// 다른 변수 생성
struct Doc
{
    int idx;
    int prio;
    Doc(int i, int p) : idx(i), prio(p) {}
    bool operator<(const Doc &d) const
    {
        // if (this->idx == d.idx)
        // {
        //     return this->prio < d.prio;
        // }
        // else
        // {
        return this->prio < d.prio;
        // }
    }
    bool operator==(const Doc &d) const
    {
        // if (this->idx == d.idx)
        // {
        //     return this->prio < d.prio;
        // }
        // else
        // {
        return (this->prio == d.prio);
        // }
    }
    bool operator!=(const Doc &d) const
    {
        // if (this->idx == d.idx)
        // {
        //     return this->prio < d.prio;
        // }
        // else
        // {
        return !(*this == d);
        // }
    }
    friend ostream &operator<<(ostream &out, Doc &d)
    {
        out << "(idx: " << d.idx << ", prioirty: " << d.prio << ")";
        return out;
    }
};
// 입력, 테스트 출력
void input();
void print(int, queue<Doc>);

void sol(int n, int target_doc, priority_queue<Doc> &PQprinter, queue<Doc> &printer)
{
    int cnt = 0;
    while (!PQprinter.empty())
    {
        while (PQprinter.top() != printer.front())
        {
            Doc now = printer.front();
            printer.pop();
            printer.push(now);
        }
        cnt++;
        if (target_doc == printer.front().idx)
        {
            cout << cnt << endl;
            return;
        }

        PQprinter.pop();
        printer.pop();
    }
    print(n, printer);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("simulation-1996_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    // sol();

    return 0;
}

void input()
{
    cin >> t;
    while (t)
    {
        int n, target_doc;
        cin >> n >> target_doc;

        priority_queue<Doc> PQprinter;
        queue<Doc> printer;
        for (int i = 0; i < n; i++)
        {
            int prio;
            cin >> prio;

            PQprinter.push(Doc(i, prio));
            printer.push(Doc(i, prio));
        }
        // print(n, printer);
        sol(n, target_doc, PQprinter, printer);
        t--;
    }
}
void print(int n, queue<Doc> printer)
{
    for (int i = 0; i < n; i++)
    {
        Doc now = printer.front();
        cout << now << " " << endl;
        printer.pop();
    }
    cout << endl;
}
