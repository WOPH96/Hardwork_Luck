// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입력변수생성
int n, m;
int r, c, d;
int MAP[51][51] = {0};
// bool cleaned[51][51] = {false};
// 다른 변수 생성
//          북  동 남  서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

enum ROOM
{
    DIRTY,
    WALL,
    CLEANED
};

struct Node{
    int y;
    int x;
    Node(int y, int x) : y(y), x(x) {}
};
bool is_wall(int y,int x){
    return MAP[y][x] == WALL;
}
// 입력, 테스트 출력
void input();
void print();

void sol(){
    //시작지점 클리닝
    MAP[r][c] = CLEANED;
    int clean_cnt = 1;
    int turn_cnt = 0;
    queue<Node> q;
    q.push(Node(r,c));

    while(!q.empty()){
        Node now = q.front();
        q.pop();
        //반시계 방향으로 회전, 청소되지 않은 빈칸을 찾을때까지
        while(turn<5){
            turn_cnt++;
            next_d = (d+turn_cnt)%4;
            //이동
            int ny = now.y + dy[next_d];
            int nx = now.x + dx[next_d];
            //범위 체크
            if(is_wall(ny,nx)){
                turn++;
                continue;
            }
            
        }
    }

    
    cout << clean_cnt  << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("simulation-14503_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();
    print();

    return 0;
}

void input()
{
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
void print()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
