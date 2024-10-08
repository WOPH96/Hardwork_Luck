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
};

// 입력변수생성
int n;
int graph[21][21] = {0};
vector<Fish> fishes;

Shark babyshark{0, 0};

// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

struct cmp
{

    int distance(const Fish &f)
    {
        // 사이즈를 포함할 것인가.. 말것인가..
        // 포함해야됨. 먹을 수 있고, 가까운 놈으로 선정
        // size가 크거나 같으면 일단 distance 99999로 선정
        // 먹으려면 작아야 하기 때문
        if (f.size >= babyshark.size)
            return 99999;
        else
        {
            // 거리는 (물고기 x - 상어 x ) + abs(물고기 y - 상어 y)
            return abs(f.x - babyshark.x) + abs(f.y - babyshark.y);
        }
    }
    // pq에 직접 넣을 떄는, max heap이기 떄문에, 왼쪽이 크게끔 하면 왼쪽이 맨앞에 나온다. 함수포인터 그대로 넣음, ()는 알아서 pq가 호출한다.
    // sort함수는 오름차순이 기본이기 떄문에(min) 오른쪽이 크게끔 하면 왼쪽이 맨앞에 나온다. cmp()를 넣어서 sorting한다.
    bool operator()(const Shark &f1, const Shark &f2)
    {
        if (f1.y == f2.y)
        {
            return f1.x > f2.x; // 왼쪽에 있는 놈 먼저 3
        }
        else
            return f1.y > f2.y; // 위쪽에 있는놈 먼저 2
    }
};
// priority_queue<Fish, vector<Fish>, cmp> fishes;
bool is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < n);
}
bool bfs(bool (*Fish_visited)[21])
{

    bool visited[21][21] = {0};

    priority_queue<Shark, vector<Shark>, cmp> q;
    q.push(babyshark);
    visited[babyshark.y][babyshark.x] = true;

    // 상,좌를 먼저 돌도록 순서를 설정
    // >> 아기상어가 위에 있을 땐, 오른쪽으로 가는게 맞는방향임....
    // queue 자체를 pq로 바꿔서, 왼쪽위가 오게끔 하자
    int dy[4] = {-1, 0, 0, 1};
    int dx[4] = {0, -1, 1, 0};

    while (!q.empty())
    {
        Shark now = q.top();
        q.pop();
        cout << now.y << "," << now.x << endl;
        // if문을 넣고,now.x now.y가 물고기면 잡아먹는걸로 변경
        // 한번에 작업하는게 아닌, pq에 넣는 과정이 필요함

        // 현재가 잡아먹을수 잇는 물고기라면
        if (0 < graph[now.y][now.x] && graph[now.y][now.x] < now.size &&
            !Fish_visited[now.y][now.x])
        {

            babyshark.y = now.y;
            babyshark.x = now.x;
            babyshark.dist = now.dist;
            babyshark.stack++;
            if (babyshark.stack == babyshark.size)
            {
                babyshark.size++;
                babyshark.stack = 0;
            }
            Fish_visited[now.y][now.x] = true;
            // 잡아먹기
            graph[now.y][now.x] = 0;
            return true;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            // 올바른 경로고, 방문한적 없으면
            if (!is_valid(ny, nx))
                continue;
            if (visited[ny][nx])
                continue;
            // 지나갈 수 있는 길이면
            if (0 <= graph[now.y][now.x] && graph[now.y][now.x] <= now.size)
            {
                // cout << ny << "," << nx << endl;
                q.push(Shark(ny, nx, now.size, now.dist + 1));
                visited[ny][nx] = true;
            }
        }
    }
    // 다 돌았는데 아기상어보다 작은 애가 없으면
    return false;
}
void sol()
{
    int cnt = 0;
    bool Fish_visited[21][21] = {0};
    while (1)
    { // 가까운 물고기만 중요하니까 한개만 정렬
        // pop_back으로 효율적으로 물고기 잡아먹을 수 있음
        // 맨 마지막 1개에만 정렬값 배치
        // nth_element(fishes.begin(), fishes.end() - 1, fishes.end(), cmp());
        // partial_sort(fishes.begin(), fishes.begin() + 1, fishes.end(), cmp());
        // partial_sort(fishes.end() - 2, fishes.end() - 1, fishes.end(), cmp());
        // sort(fishes.begin(), fishes.end(), cmp());
        cnt++;
        cout << cnt << endl;
        if (!bfs(Fish_visited))
            break;
        print();

        // if (cnt > 12)
        //     break;
    }
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
    // print();
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
                // fishes.push(Fish(i, j, graph[i][j]));
                // fishes.push_back(Fish(i, j, graph[i][j]));
                fishes.emplace_back(i, j, graph[i][j]);
            }
            else if (graph[i][j] == 9)
            {

                babyshark.y = i;
                babyshark.x = j;
                graph[i][j] = 0;
            }
        }
    }
}
void print()
{
    int debug[21][21] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            if (i == babyshark.y && j == babyshark.x)
                cout << "9 ";
            else
                cout << debug[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << debug[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // while (!fishes.empty())
    // {
    //     Fish now = fishes.top();
    //     cout << now << endl;
    //     fishes.pop();
    // }
    // for (auto &fish : fishes)
    // {
    //     cout << fish << endl;
    // }
    cout << "Babyshark : " << babyshark << endl;
    cout << endl;
}
