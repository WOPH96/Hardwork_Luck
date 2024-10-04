// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

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
vector<Fish> fishes;
Shark *babyshark;
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

bool cmp(Fish &f1, Fish &f2)
{
    return true;
}
void sol()
{
    // 매번 sort 비효율적일수도 ?
    // 아기상어의 현재 시점 기준에서 제일 위/왼쪽에 있는 물고기 찾아내기
    sort(fishes.begin(), fishes.end(), cmp);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-16236_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
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
                fishes.push_back(Fish(i, j, graph[i][j]));
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

    for (auto &fish : fishes)
    {
        cout << fish << endl;
    }
    cout << "Babyshark : " << *babyshark << endl;
}
