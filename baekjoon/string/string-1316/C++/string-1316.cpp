// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 입력변수생성
int n;
vector<string> strs;

// 다른 변수 생성
int alpa[26]={0};
// 입력, 테스트 출력
void input();
void print();

void sol(){
    int group_word_cnt=0;
    for(auto &str : strs){
        stack <char> st;
        bool break_flag=false;
        for(char &c : str){
            if(alpa[c-'a']==0){
                st.push(c);
                alpa[c-'a']++;
            }
            else{
                cout << "top : " << st.top() << " ";
                if(!st.empty()&&st.top()!=c){
                    cout << "wrong group word " << str << endl;
                    break_flag=true;
                    break;
                }
            }
        }
        if(!break_flag){
            group_word_cnt++;
        }
    }
    cout << group_word_cnt << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("string-1316_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}

void input() {
    cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
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
