// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 입력변수생성
int n;
int graph[21][21] = {0};
// 다른 변수 생성
struct Fish
{
    int y, x, size;

    Fish(int y, int x, int size) : y(y), x(x), size(size) {}
    friend ostream &operator<<(ostream &out, Fish &f)
    {
        out << "(" << f.y << "," << f.x << ") size: " << f.size;
        return out;
    }
};
struct Shark : Fish
{
    int dist;
    int stack;
    Shark(int y, int x, int size = 2, int dist = 0, int stack = 0) : Fish(y, x, size), dist(dist), stack(stack) {}
    friend ostream &operator<<(ostream &out, Shark &s)
    {
        out << "(" << s.y << "," << s.x << ") size: " << s.size << " dist : " << s.dist << " stack :" << s.stack;
        return out;
    }
    void grow()
    {
        if (this->stack == this->size)
        {
            this->size++;
            this->stack = 0;
        }
    }
};

struct cmp
{
    bool operator()(Shark &s1, Shark &s2)
    {
        if (s1.y == s2.y)
        {
            return s1.x < s2.x;
        }
        else
            return s1.y < s2.y;
    }
};

Shark babyshark{0, 0};
// 입력, 테스트 출력

void print();

bool is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < n);
}
Shark find_nearest_fish()
{
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    // while (1)
    // {
    bool visited[21][21] = {false};
    queue<Shark> q;
    q.push(babyshark);
    visited[babyshark.y][babyshark.x] = true;
    int min_dist = 99999;
    vector<Shark> fishes;
    while (!q.empty())
    {
        Shark now = q.front();
        q.pop();
        // 다음 장소가 물고기이고, 최소거리와 동일거리라면
        if (min_dist >= now.dist)
        {
            if (0 < graph[now.y][now.x] && graph[now.y][now.x] < now.size)
            {
                min_dist = now.dist;
                fishes.push_back(now);
            }
        }
        // 잡아먹을수 있는 물고기 한마리라도 찾았으면, 최소거리 못지키면 끝내
        else
            continue;
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(ny, nx))
                continue;
            if (visited[ny][nx])
                continue;
            if (graph[ny][nx] <= now.size)
            {
                q.push(Shark(ny, nx, now.size, now.dist + 1));
                visited[ny][nx] = true;
            }
        }
    }
    // 물고기 못찾았으면
    if (fishes.empty())
    {
        return Shark(-1, -1);
    }
    // 찾았으면
    else
    {
        sort(fishes.begin(), fishes.end(), cmp());
        return fishes[0];
    }

    // }
}
void sol()
{
    // 현재 샤크 기준 가까운 생선 찾기
    // int cnt = 0;
    int distance = 0;
    while (1)
    {
        Shark near_fish = find_nearest_fish();
        if (near_fish.y == -1)
            break;
        // cout << "fish" << near_fish << endl;
        babyshark.x = near_fish.x;
        babyshark.y = near_fish.y;
        distance += near_fish.dist;
        babyshark.stack++;
        babyshark.grow();

        graph[babyshark.y][babyshark.x] = 0;

        // cout << "babyshark" << babyshark << endl;

        // cnt++;
        // if (cnt > 3)
        //     break;
    }
    cout << distance << endl;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 9)
            {
                babyshark.y = i;
                babyshark.x = j;
                graph[i][j] = 0;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("graph_search-16236_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
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

    cout << "babyshark ->" << babyshark << endl;
}
