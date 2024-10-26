#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Pos{
    int y,x;
    Pos(int y,int x): y(y),x(x) {}
};
void print(vector<Pos> & ps){
    for (auto &p : ps){
        cout << p.y << ","<< p.x << endl;
    }
    cout << endl;
}

bool bingo(vector<Pos> & ps){
    vector<Pos> bingoset[8];
    bingoset[0].emplace_back(0,0);
    bingoset[0].emplace_back(1,1);
    bingoset[0].emplace_back(2,2);

    bingoset[2].emplace_back(0,0);
    bingoset[2].emplace_back(0,1);
    bingoset[2].emplace_back(0,2);

    for (auto &p : ps){
        for(int i=0;i<8;i++){
            for(auto &bingo:bingoset[i]){

            }
        }
    }
    /*
    bingo  
    00 11 22
    02 11 20
    0 123
    1 123
    2 123
    123 0
    123 1
    123 2
    */

}

int solution(vector<string> board) {
    int answer = -1;
    vector<Pos> pos_of_O;
    vector<Pos> pos_of_X;

    for(int i=0;i<3;i++){
        string str = board[i];
        for(int j=0;j<3;j++){
            if(str[j] == 'O'){
                pos_of_O.emplace_back(i,j);
            }
            else if(str[j] == 'X'){
                pos_of_X.emplace_back(i,j);
            }
        }
    }
    print(pos_of_O);
    print(pos_of_X);

    // Check 1
    if(pos_of_X>pos_of_O)
        answer = 0;

    // Check 2
    else if(bingo(pos_of_O)){
        if(pos_of_X.size()!=pos_of_O.size()-1)
            answer = 0;
    }
    // Check 3
    else if (bingo(pos_of_X)){
        if(pos_of_O.size()!=pos_of_X.size())
            answer = 0;
    }
    answer = 1;
    return answer;
    /*
    ㅇㅏㅇㅣㄷㅣㅇㅓ
    O -> X
    1. 0<= #X <= #O 
    2. #O == bingo -> #X == #O-1
    3. #X == bingo -> #O == #X


    */
}