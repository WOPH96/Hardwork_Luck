// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define timepq priority_queue<Time,vector<Time>,cmp>
// 입력변수생성
int n;

struct Time
{
    int start, end;
    Time(int s, int e) : start(s), end(e) {}
};
// 다른 변수 생성
struct cmp{
    bool operator()(Time &a, Time &b){
        return a.end > b.end;
    }
};

vector<Time> lectures;

timepq classrooms;
// 입력, 테스트 출력

void print();

void sol()
{
    sort(lectures.begin(), lectures.end(), 
        [](Time &a, Time &b) { return a.end < b.end; });
    int cnt = 0;
    
    for(auto &lecture : lectures){
        if(classrooms.empty()){
            classrooms.push(lecture);
            cnt++;
        }
        else{
            
            if(classrooms.top().end <= lecture.start){
                
                cnt++;
            }
            classrooms.push(lecture);
            
            // bool insert_flag = false;
            // for(int idx = 0;idx<classrooms.size();idx++){
            //     if(classrooms[idx].top().end <= lecture.start){
            //         classrooms[idx].push(lecture);
            //         insert_flag = true;
            //         break;
            //     }
            // }
            // if (!insert_flag){
            //     priority_queue<Time,vector<Time>,cmp> tmp;
            //     tmp.push(lecture);
            //     classrooms.push_back(tmp);
                
            // }
        }
        
        
    }
    cout << classrooms.top().start << " " << classrooms.top().end << endl;    
    cout << cnt << endl;   
}

void input()
{
    cin >> n;
    for(int i=0;i<n;i++){
        int start, end;
        cin >> start >> end;
        lectures.emplace_back(start,end);
        
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-11000_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for(auto & elem : lectures){
        cout << elem.start << " " << elem.end << endl;
    }
    cout << endl;
    // for(auto &elem : classrooms){
    //     while(!elem.empty()){
    //         cout << elem.top().start << " " << elem.top().end << endl;
    //         elem.pop();
    //     }
    //     cout << endl;
    // }
}
