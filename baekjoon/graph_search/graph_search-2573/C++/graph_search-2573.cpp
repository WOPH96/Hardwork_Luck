// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n,m;
int prev_graph[301][301] = {0};
int next_graph[301][301] = {0};
// 다른 변수 생성

// 입력, 테스트 출력

void print();
bool is_valid(int y, int x){
    return (y >= 0 && y < n && x >= 0 && x < m);
}
void sol(){
    int dy[4]={0,0,1,-1};
    int dx[4]={1,-1,0,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(prev_graph[i][j]==0){
                continue;
            }
            else{
                next_graph[i][j] = prev_graph[i][j];
                for(int k=0;k<4;k++){
                    int ny = i+dy[k];
                    int nx = j+dx[k];
                    if(!is_valid(ny,nx)){
                        continue;
                    }
                    if(prev_graph[ny][nx]==0 && next_graph[i][j]!=0){
                        
                        next_graph[i][j]-=1;
                        
                    }
                }
            }
        }
    }
    prev_graph = next_graph;
}

void input() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> prev_graph[i][j];
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-2573_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}


void print() {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << prev_graph[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout <<  next_graph[i][j] << " ";
        }
        cout << endl;
    }
} 
