// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct Fish
{
    int y, x;

    int size;
    Fish(int y, int x, int size = 2, int dist = 0) : y(y), x(x), size(size) {}
    friend ostream &operator<<(ostream &out, Fish &f)
    {
        out << "(" << f.y << "," << f.x << ") size: " << f.size;
        return out;
    }
    bool operator<(const Fish &f) const;
};
struct Shark : Fish
{
    int dist;
    Shark(int y, int x, int size = 2, int dist = 0) : Fish(y, x, size), dist(dist) {}
    friend ostream &operator<<(ostream &out, Shark &s)
    {
        out << "(" << s.y << "," << s.x << ") size: " << s.size << " dist : " << s.dist;
        return out;
    }
};

// 입력변수생성
int n;
int graph[21][21] = {0};
// vector<Fish> fishes;
priority_queue<Fish> fishes;
Shark *babyshark;
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

bool Fish::operator<(const Fish &f2) const
{
    if (this->size == f2.size)
    {
        if (this->y == f2.y)
        {
            return this->x > f2.x; // 왼쪽에 있는 놈 먼저 3
        }
        else
            return this->y > f2.y; // 위쪽에 있는놈 먼저 2
    }

    else
        return this->size > f2.size; // 작은놈 먼저 1
}
void sol()
{
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-16236_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    print();
    delete babyshark;
    return 0;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            if (1 <= graph[i][j] && graph[i][j] <= 6)
            {
                fishes.push(Fish(i, j, graph[i][j]));
                // fishes.emplace_back({i, j, graph[i][j], 0});
            }
            else if (graph[i][j] == 9)
            {
                babyshark = new Shark(i, j);
            }
        }
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    while (!fishes.empty())
    {
        Fish now = fishes.top();
        cout << now << endl;
        fishes.pop();
    }
    cout << "Babyshark : " << *babyshark << endl;
}
