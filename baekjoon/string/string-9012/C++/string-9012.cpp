// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 입력변수생성
int n;
vector<string> strs;
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

void sol(){
    
    
    for(string & str : strs){
        stack<char> s;
        bool break_flag = false;
        for(char & c : str){
            if(c=='(')
            {
                s.push(c);
                
            }
            else if(c==')'){
                if( s.empty())
                {
                    cout << "NO" << endl;
                    break_flag=true;
                    break;
                }
                else if(s.top()=='(')
                {
                    s.pop();
                    
                }
            }
        }
        if(!break_flag){
            if(s.empty() ){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("string-9012_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void input() {
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)   
    {
        string str;
        getline(cin,str);
        strs.push_back(str);
    }
}
void print() {
    for(auto s : strs){
        cout << s << endl;
    }
} 
