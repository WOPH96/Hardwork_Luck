// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int F, S, G, U, D;
bool visited[1000001]={false};
// 다른 변수 생성

// 입력, 테스트 출력

void print();

struct node{
  int pos;
  int button_num;
  node(int p,int b):pos(p),button_num(b){}
};

void sol(){
    queue<node> q;
    q.emplace(S,0);
    visited[S]=true;
    while(!q.empty()){
        node now = q.front();
        q.pop();
        if(now.pos==G){
            cout << now.button_num << endl;
            return;
        }
        int toUp, toDown;
        toUp = now.pos+ U;
        toDown = now.pos - D;
        if(toUp<=F && !visited[toUp]){
            q.emplace(toUp,now.button_num+1);
            visited[toUp]=true;
        }
        if(toDown>=1 && !visited[toDown]){
            q.emplace(toDown,now.button_num+1);
            visited[toDown]=true;
        }
        
    }
    cout << "use the stairs" << endl;
}

void input() {
    cin >> F >> S >> G >> U >> D;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    //freopen("graph_search-5014_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}


void print() {

} 
