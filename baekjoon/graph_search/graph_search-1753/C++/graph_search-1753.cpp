// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int dst;
    int w;
}dst_t;
// 입력변수생성
int v, e;
int start;
vector<dst_t> graph[20001];
// 입력변수생성

// 입력, 테스트 출력
void input();
void print();

// void sol(){
// }

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-1753_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol();

    return 0;
}

void input() {
    cin >> v >> e;
    cin >> start;
    for (int i=0; i<e;i++){
        int src, dst, w;
        cin >> src >> dst >> w;
        graph[src].push_back({dst,w});
        
        
    }
}
void print() {
    for (int i=0; i<v;i++){
        cout << i << "  ";
        for(auto &elem : graph[i]){
            cout << "(" << elem.dst << "," << elem.w << ")" << " ";
        }
        cout << endl;
    }
    cout << endl;
} 
