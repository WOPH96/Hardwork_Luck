// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 입력변수생성
int t;
// 다른 변수 생성

// 입력, 테스트 출력
struct Pos
{
    int y, x;
    Pos() : y(0), x(0) {}
    Pos(int y, int x) : y(y), x(x) {}
    friend ostream &operator<<(ostream &out, Pos &p)
    {
        out << "(" << p.y << "," << p.x << ")";
        return out;
    }
    bool operator==(const Pos &p) const
    {
        return (this->y == p.y && this->x == p.x);
    }
};
void print(int n, Pos &house, Pos *cvst, Pos &dest);

int get_dist(const Pos &from, const Pos &to)
{
    return abs(from.x - to.x) + abs(from.y - to.y);
}
bool is_visited(vector<Pos> &visited, Pos &data)
{
    // 내부에 있다 -> end가 아님
    return (find(visited.begin(), visited.end(), data) != visited.end());
}
void sol(Pos &house, Pos *cvst, Pos &dest, int size)
{
    // 50미터 *20 == 1000 m 까지는 이동 가능함
    // 아기상어 때처럼,, 분신 가고 이동?
    // n을 기준으로 가져온다.
    // 그냥 다 큐에 넣어 알아서 할거
    queue<Pos> q;
    q.emplace(house);
    vector<Pos> visited;
    while (!q.empty())
    {
        Pos now = q.front();
        q.pop();
        if (get_dist(now, dest) <= 1000)
        {
            cout << "happy" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            if (is_visited(visited, cvst[i])) // 방문한적 있으면
                continue;

            if (get_dist(now, cvst[i]) <= 1000)
            {
                q.push(cvst[i]);
                visited.push_back(cvst[i]);
            }
        }
    }
    cout << "sad" << endl;
}

void input()
{
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;
        Pos house;
        Pos *cvst = new Pos[n];
        Pos dest;
        cin >> house.y >> house.x;

        for (int i = 0; i < n; i++)
        {
            cin >> cvst[i].y >> cvst[i].x;
        }
        cin >> dest.y >> dest.x;

        sol(house, cvst, dest, n);
        // print(n, house, cvst, dest);
        delete[] cvst;
        t--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-9205_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    // print();

    return 0;
}

void print(int n, Pos &house, Pos *cvst, Pos &dest)
{
    cout << house << endl;
    for (int i = 0; i < n; i++)
    {
        cout << cvst[i] << endl;
    }
    cout << dest << endl;
    cout << endl;
}
