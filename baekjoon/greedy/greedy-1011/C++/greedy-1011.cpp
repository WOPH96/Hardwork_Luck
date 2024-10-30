// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int t;
// 다른 변수 생성

// 입력, 테스트 출력

void print(int,int);

struct Move{
    int pos, cur, op_time;
    Move(int p, int c, int t) : pos(p), cur(c), op_time(t){}
};
void sol(int start,int target){
    
    //bfs
    bool *visited = new bool[target+1];
    fill(visited,visited+target+1,false);
    queue<Move> q;
    
    q.emplace(start,0,0);
    visited[start] = true;
    while(!q.empty()){
        Move now = q.front();
        q.pop();
        if(now.cur == target){
            cout << now.op_time << endl;
            return;
        }
        for(auto &year_speed : {now.cur-1,now.cur,now.cur+1}){
            if(year_speed <0) continue;
            int next = now.pos + year_speed;
            if(visited[next]) continue;
            q.emplace(next,year_speed,now.op_time+1);
            visited[next] = true;
        }
    }
    delete [] visited;
}

void input() {
    cin >> t;
    while(t){
        int start, target;
        cin >> start >> target;
        
        print(start,target);
        sol(start,target);
        t--;
    }
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-1011_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    // print();./

    return 0;
}


void print(int start, int target) {
    cout << start << target <<"\n"<< endl ;
} 
