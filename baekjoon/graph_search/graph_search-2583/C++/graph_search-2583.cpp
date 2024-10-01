// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Rect{
    int x1,y1,x2,y2;
    Rect(int x1,int y1,int x2,int y2):x1(x1), y1(y1),x2(x2),y2(y2){}
};

struct Node{
    int y;
    int x;
    Node(int y, int x) : y(y), x(x) {}
    
};
enum PAPER{
    EMPTY,
    RECT
};
// 입력변수생성
int m,n,k;
vector<Rect> rects;
int paper[101][101]={0};

// 다른 변수 생성
bool visited[101][101]={false};
vector<int> areas;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
// 입력, 테스트 출력
void input();
void print();


void fill_paper(const Rect & rect){
    // cout << rect.x1 << " " << rect.y1 << " " << rect.x2 << " " << rect.y2 << endl;
    // for(int i=rect.y1;i<=rect.y2;i++){
    //     for(int j=rect.x1;j<=rect.x2;j++)
    //         paper[i][j] = 1;
    // }

        for (int i = rect.y1; i < rect.y2; i++)
            for (int j = rect.x1; j < rect.x2; j++)
                paper[i][j] = RECT;

}
bool is_valid(int y,int x){
    return (y>=0 && y<m && x>=0 && x<n);
}
int bfs(Node &&start){
    if(visited[start.y][start.x] || paper[start.y][start.x] == RECT) 
        return 0;
    
    queue<Node> q;
    q.push(start);
    visited[start.y][start.x] = true;
    int area=0;
    while(!q.empty()){
        Node now = q.front();
        q.pop();
        area++;
        for(int i=0;i<4;i++){
            int ny = now.y +dy[i];
            int nx = now.x +dx[i];
            if(!is_valid(ny,nx)) continue;
            if(!visited[ny][nx] && paper[ny][nx] == EMPTY) {
                q.push(Node(ny,nx));
                visited[ny][nx] = true;
            }
            
        }
        
    }
    
    return area;
}
void sol(){
    int cnt = 0;
    for (auto rect : rects){
        fill_paper(rect);
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int area = bfs(Node(i,j));
            if(area) {
                cnt++;
                areas.push_back(area);
            }
        }
    }
    sort(areas.begin(),areas.end());
    cout << cnt << endl;
    for (auto area : areas){
        cout << area << " ";
    }

    // cout << endl;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-2583_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    // print();
    return 0;
}

void input() {
    cin >> m >> n >> k;
    for(int i=0;i<k;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rects.push_back(Rect(x1,y1,x2,y2));
    }
}
void print() {
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << paper[i][j] << " ";
        }
        cout << endl;
    }
    cout <<endl;
} 
